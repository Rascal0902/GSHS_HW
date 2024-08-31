#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <time.h>

using namespace std;
struct CUBE {char colors[25];vector<int> turns;};
queue<CUBE> Q;
map<string,int> M;

int trans[7][24]={
  0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,
  0,9,2,11,4,5,6,7,8,21,10,23,14,12,15,13,3,17,1,19,20,18,22,16,
  0,18,2,16,4,5,6,7,8,1,10,3,13,15,12,14,23,17,21,19,20,9,22,11,
  2,0,3,1,8,9,6,7,12,13,10,11,16,17,14,15,4,5,18,19,20,21,22,23,
  1,3,0,2,16,17,6,7,4,5,10,11,8,9,14,15,12,13,18,19,20,21,22,23,
  13,15,2,3,1,5,0,7,8,9,10,11,12,23,14,22,18,16,19,17,20,21,4,6,
  6,4,2,3,22,5,23,7,8,9,10,11,12,0,14,1,17,19,16,18,20,21,15,13

};


CUBE turn(CUBE x,int n)
{
  CUBE t;
  for(int i=0;i<24;i++)
    t.colors[i]=x.colors[trans[n][i]];
  t.colors[24]='\0';
  t.turns=x.turns;
  t.turns.push_back(n);
  return  t;
}

int cnt=0;
bool chk(CUBE x)
{
  cnt++;
  for(int i=0;i<=2;i++)
    for(int t=i*4,j=1;j<=3;j++)
      if(x.colors[t]!=x.colors[t+j])
        return false;
  return true;
}

void bfs()
{
  CUBE t,tt;
  while(!Q.empty())
  {
    t=Q.front();
    Q.pop();
    if(chk(t)==true)
    {
      printf("Solved! How to rotate(123456:RR'BB'DD'):\n");
      for(int i=0;i<t.turns.size();i++)
        printf("%d",t.turns[i]);
      printf("\n");
      return;
    }
    else
    {
      for(int i=1;i<=6;i++)
      {
        tt=turn(t,i);
        if(M[tt.colors]!=1)
        {
          M[tt.colors]=1;
          Q.push(tt);
        }
      }
    }
  }
}

int main(void)
{
  CUBE t;
  printf("222cube colors: ");
  scanf("%s",t.colors);
  printf("BFS started...\n\n");
  Q.push(t);
  M[t.colors]=1;
  clock_t st=clock();
  bfs();
  printf("%.2f(sec)\n",float(clock()-st)/CLOCKS_PER_SEC);
  printf("%d cubes checked!\n",cnt);
  return 0;
}
