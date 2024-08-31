#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<stdlib.h>//문자열 변환
#include<algorithm>
#include<utility>
using namespace std;
typedef long long int ll;
int ans[1000];
int t;
int main()
{
    char on[10];
    t=0;
    while(1)
    {
        cout << "choose start or finish " ;

        cin.getline(on, 20);
        if(strcmp( on, "finish" )==0)
        {
            return 0;
        }
        else if((strcmp( on, "finish" )!=0)&&(strcmp( on, "start" )!=0))
        {
            printf("error try again\n\n");
        }
        else
        {
            cout << "choose" << " count? " << " ans check? "<< endl ;
            cin.getline(on, 20);
            if(strcmp ( on, "count" )==0)
            {
                cout << "info?" << " big number?(ll) , number?(int) , small number?(float)" <<endl ;
                cin.getline(on, 20);
                if(strcmp( on, "big number" )==0)
                {
                    cout << "write the calculation and write f if you are done" << endl;
                    ll sum;
                    int i=0,x,j;
                    char y;
                    vector <ll> v1;
                    vector <char> v2;

                    while(1)
                    {
                        cin >> x;
                        v1.push_back (x);
                        cin >> y;
                        v2.push_back (y);
                        if(v2[i]=='f')
                        {
                            break;
                        }
                        i++;
                    }
                    cout << "scan ok" << endl;
                    sum=v1[0];
                    for(j=0; j<i; j++)
                    {
                        if(v2[j]=='+')
                        {
                            sum+=v1[j+1];
                        }
                        else if(v2[j]=='-')
                        {
                            sum-=v1[j+1];
                        }
                        else if(v2[j]=='/')
                        {
                            sum/=v1[j+1];
                        }
                        else if(v2[j]=='%')
                        {
                            sum%=v1[j+1];
                        }
                        else if(v2[j]=='*')
                        {
                            sum*=v1[j+1];
                        }
                        else
                        {
                            cout << " there is no calculation in this calculator"  << endl<< endl;
                        }
                    }
                    cout << "sum=" << sum  << endl<< endl;

                }

                else if(strcmp( on, "number" )==0)
                {
                    cout << "write the calculation and write f if you are done" << endl;
                    int i=0,x,j,sum;
                    char y;
                    vector <int> v1;
                    vector <char> v2;

                    while(1)
                    {
                        cin >> x;
                        v1.push_back (x);
                        cin >> y;
                        v2.push_back (y);
                        if(v2[i]=='f')
                        {
                            break;
                        }
                        i++;
                    }
                    cout << "scan ok" << endl;
                    sum=v1[0];
                    for(j=0; j<i; j++)
                    {
                        if(v2[j]=='+')
                        {
                            sum+=v1[j+1];
                        }
                        else if(v2[j]=='-')
                        {
                            sum-=v1[j+1];
                        }
                        else if(v2[j]=='/')
                        {
                            sum/=v1[j+1];
                        }
                        else if(v2[j]=='%')
                        {
                            sum%=v1[j+1];
                        }
                        else if(v2[j]=='*')
                        {
                            sum*=v1[j+1];
                        }
                        else
                        {
                            cout << " there is no calculation in this calculator"  << endl<< endl;
                        }
                    }
                    cout << "sum=" << sum  << endl<< endl;

                }
                else if(strcmp( on, "small number" )==0)
                {
                    cout << "write the calculation and write f if you are done" << endl;
                    float sum;
                    int i=0,x,j;
                    char y;
                    vector <float> v1;
                    vector <char> v2;

                    while(1)
                    {
                        cin >> x;
                        v1.push_back (x);
                        cin >> y;
                        v2.push_back (y);
                        if(v2[i]=='f')
                        {
                            break;
                        }
                        i++;
                    }
                    cout << "scan ok" << endl;
                    sum=v1[0];
                    for(j=0; j<i; j++)
                    {
                        if(v2[j]=='+')
                        {
                            sum+=(float)v1[j+1];
                        }
                        else if(v2[j]=='-')
                        {
                            sum-=(float)v1[j+1];
                        }
                        else if(v2[j]=='*')
                        {
                            sum*=(float)v1[j+1];
                        }
                        else if(v2[j]=='/')
                        {
                            sum/=(float)v1[j+1];
                        }
                        else
                        {
                            cout << " there is no calculation in this calculator"  << endl<< endl;
                        }
                    }
                    cout << "sum=" << sum  << endl<< endl;

                }
                else
                {
                    cout << " there is no calculation in this calculator"  << endl<< endl;
                }

            }
            else if(strcmp ( on, "ans check" )==0)
            {
                cout << " check? " << " new? " <<endl ;
                cin.getline(on, 20);
                if(strcmp ( on, "new" )==0)
                {
                    int scan;
                    cout << "write" << endl;
                    cin >> scan;
                    ans[t]=scan;
                    t++;
                    cout <<"scan complete"<< endl;
                }
                else if(strcmp ( on, "check" )==0)
                {
                    int i;
                    for(i=0;; i++)
                    {
                        if(ans[i]==0)
                        {
                            cout << "check finish"<<endl;
                            break;
                        }
                        else
                        {
                            printf("ans[%d]= %d\n",i,ans[i]);
                        }
                    }

                }
            }
            else
            {
                cout << " there is no calculation in this calculator"  << endl<< endl;
            }

        }
    }
    return 0;
}
