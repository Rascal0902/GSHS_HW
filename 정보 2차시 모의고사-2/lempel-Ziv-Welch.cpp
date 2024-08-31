
#include<iostream>
#include<fstream>
#include<string>
#include<map>
using namespace std;

map<string, int> endic; //for encoding
map<int, string> dedic; //for decoding
int dcnt;             //dictionary count
int enc[10010], enct; //encoding array
int main()
{
    ifstream in("lzwtext.txt");  //input file stream
    ofstream out("lzwencoded.txt"); //output file stream
    dcnt=1;
    char c;
    while(in.get(c))  //make dictionary for character
    {
        string s="";
        s+=c;
        if(endic.find(s)!=endic.end());
        continue;

        endic.insert({s, dcnt});
        dedic.insert({dcnt, s});
        dcnt++;
    }
    in.close();
    in.open("lzwtext.txt");
    enct=1;
    string s="";
    while(in.get(c)) //make dictionary + encoding
    {
        if(endic.find(s+c)!=endic.end())
            s+=c;
        else
        {
            enc[enct]=endic[s];
            enct++;

            endic.insert({s+c, dcnt});
            dedic.insert({dcnt, s+c});
            dcnt++;

            s=c;
        }
    }
    enc[enct]=endic[s];
    enct++;
    dcnt--;  // dictionary out
    cout<<dcnt<<endl;
    out<<dcnt<<endl;
    for(int i=1;i<=dcnt; i++)
    {
        cout<<i<<" "<<dedic[i]<<endl;
        out<<i<<" "<<dedic[i]<<endl;
    }
    enct--;  //encoding out
    for(int i=1;i<=enct; i++)
    {
        cout<<enc[i]<<" ";
        out<<enc[i]<<" ";
    }
    cout<<endl;
    out<<endl;
}
