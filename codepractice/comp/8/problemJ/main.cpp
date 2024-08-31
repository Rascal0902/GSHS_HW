#include <iostream>
#include <cmath>
#define MAX 1000000
using namespace std;

int N;
int P[200][2];
char M[200][200];
double D[200][200];
double MD[200];

int main()
{
    cin>>N;
    for(int i=1; i<=N; i++)
        cin>>P[i][0]>>P[i][1];
    for(int i=1; i<=N; i++)
    {
        cin>>M[i]+1;
        for(int j=1; j<=N; j++)
        {
            if(i==j) D[i][j]=0.0;
            else if(M[i][j]=='1')
            {
                double dx=P[i][0]-P[j][0];
                double dy=P[i][1]-P[j][1];
                D[i][j]=sqrt(dx*dx+dy*dy);
            }
            else D[i][j]=MAX;
        }
    }

    for(int k=1; k<=N; k++)
    {
        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=N; j++)
            {
                if(D[i][k]!=MAX && D[k][j]!=MAX) D[i][j]=min(D[i][k]+D[k][j], D[i][j]);
            }
        }
    }

    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            if(D[i][j]!=MAX && i!=j) MD[i]=max(MD[i], D[i][j]);
        }
    }

    double ans=MAX;

    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            if(D[i][j]==MAX)
            {
                double dx=P[i][0]-P[j][0];
                double dy=P[i][1]-P[j][1];
                ans=min(MD[i]+MD[j]+sqrt(dx*dx+dy*dy), ans);
            }
        }
    }
    for(int i=1;i<=N;i++) ans=max(ans, MD[i]);

    printf("%.6lf", ans);
    return 0;
}
