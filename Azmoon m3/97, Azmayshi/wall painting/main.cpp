#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=10567;
int dp[400][4][4][4];
int c[1010][1010];
int solve(int n,int i,int j,int k)
{
    if(n==401&&i==0&&j==0&&k==0)
        return 1;
    else if(n==401)
        return 0;
    int &ret=dp[n][i][j][k];
    if(dp[n][i][j][k])
        return dp[n][i][j][k];
    int a[3];
    a[0]=i;
    a[1]=j;
    a[2]=k;
    sort(a,a+3);
    i=a[2];
    j=a[1];
    k=a[0];
    if(i==3)
        return dp[n][i][j][k]=(solve(n+1,0,j,k))%mod;
    if(k>0)
        ret=(solve(n+1,i,j,0)+solve(n+1,i,0,k)+solve(n+1,0,j,k))%mod;
    else if(j>0)
        ret=(solve(n+1,i,0,k)+solve(n+1,0,j,k))%mod;
    else if(i>0)
        ret=(solve(n+1,0,j,k))%mod;
    if(k==0)
        ret=(ret+solve(n+1,i+(i!=0),j+(j!=0),1+min(j,1LL)+min(i,1LL)))%mod;
    return ret;
}
main()
{
    int ans=solve(1,0,0,1);
    for(int i=0;i<=1000;i++)
        c[i][0]=1;
    for(int i=1;i<=1000;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(i==j)
                c[i][j]=1;
            else
                c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
        }
    }
    cout<<(ans*c[400][100])%mod;
    return 0;
}
