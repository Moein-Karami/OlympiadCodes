#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn=73,mod=11969;
int dp[maxn][maxn][maxn][maxn][7];
int p(int x,int y)
{
    int ret=1;
    while(y)
    {
        if(y%2==1)
            ret=(ret*x)%mod;
        x=(x*x)%mod;
        y/=2;
    }
    return ret;
}
int solve(int i,int j,int k,int l,int tp)
{
    int &ret=dp[i][j][k][l][tp];
    if(ret!=-1)
        return ret;
    if(i==0&&j==0&&k==0&&l==0)
        return ret=1;
    ret=0;
    int a[5]={0,i,j,k,l};
    for(int x=1;x<=4;x++)
    {
        if(tp!=x&&a[x]>=1)
        {
            a[x]--;
            ret=(ret+solve(a[1],a[2],a[3],a[4],x))%mod;
            a[x]++;
        }
    }
    return ret;
}
main()
{
    for(int i=0;i<maxn;i++)
        for(int j=0;j<maxn;j++)
            for(int k=0;k<maxn;k++)
                for(int q=0;q<maxn;q++)
                    for(int w=0;w<7;w++)
                        dp[i][j][k][q][w]=-1;
    int n1,n2,n3,n4;
    cin>>n1>>n2>>n3>>n4;
    //cerr<<solve(n1,n2,n3,n4,0);
    //return 0;
    int ans=0;
    for(int i=1;i<=n1;i++)
        for(int j=1;j<=n2;j++)
            for(int k=1;k<=n3;k++)
                for(int l=1;l<=n4;l++)
                    ans=(ans+solve(i,j,k,l,0))%mod;
    cout<<ans;
    return 0;
}
