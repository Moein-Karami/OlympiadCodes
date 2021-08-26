#include <bits/stdc++.h>

using namespace std;
const int maxn=1010,mod=10607;
int dp[15][maxn+12];
int n;
int a[8]={972,0,273,0,932,911,0,233};
int b[8]={0,942,135,0,371,0,311,0};
int t[10];
int solve(int x,int y)
{
     //cerr<<"X & Y : "<<x<<" "<<y<<" "<<endl;
     //getchar();
    if(dp[x][y]!=-1)
        return dp[x][y];
    if(x==n+1)
        return dp[x][y]=(y==777);
    int &ret=dp[x][y];
    ret=0;
    if(a[x-1]&&b[x-1])
        ret=solve(x+1,(y*a[x-1]+x)%b[x-1]);
    else if(a[x-1]&&b[x-1]==0)
    {
        //cerr<<"SHIT"<<endl;
        for(int i=100;i<1000;i++)
            ret=(ret+solve(x+1,(y*a[x-1]+x)%i))%mod;
        //cerr<<"FUCK"<<endl;
    }
    else if(b[x-1]&&a[x-1]==0)
    {
        for(int i=100;i<1000;i++)
            ret=(ret+solve(x+1,(y*i+x)%b[x-1]))%mod;
    }
    else
    {
        for(int i=100;i<1000;i++)
        {
            for(int j=100;j<1000;j++)
            {
                ret=(ret+solve(x+1,(y*i+x)%j))%mod;
            }
        }
    }
    //cerr<<"X & Y : "<<x<<" "<<y<<" "<<ret<<endl;
    return ret;
}
main()
{
    t[1]=900;
    for(int i=2;i<10;i++)
        t[i]=(t[i-1]*900)%mod;
    for(int i=0;i<10;i++)
        for(int j=0;j<maxn;j++)
            dp[i][j]=-1;
    cin>>n;
    cout<<(solve(1,777))%mod;
    return 0;
}
