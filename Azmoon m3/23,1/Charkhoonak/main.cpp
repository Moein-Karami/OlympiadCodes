#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=10357;
int a[5010][5010],dp[5010][5010];
int tmp[100000000];
int x;
int h[5010];

int solve(int i,int j)
{
    if(dp[i][j])
        return dp[i][j];
    if(i==1)
        return dp[i][j]=a[i][j];
    return dp[i][j]=(max(solve(i-1,j)+a[i-1][j+1],a[i-1][j]+solve(i-1,j+1))+a[i][j])%mod;

}
main()
{
    cin>>x;
    ///for(int i=1;i<=x;i++)
    ///{
       /// for(int j=x;j>x-i;j--)
          ///  h[i]+=j;
    ///}
    ///a[1][1]=mod%10;
    ///tmp[1]=mod%10;
    ///for(int i=1;i<=x;i++)
    ///{
       /// for(int j=1;j<=x-i+1;j++)
        ///{
            ///if(i!=1||j!=1)
            ///{
               /// a[i][j]=(tmp[h[i-1]+j-1]+tmp[(h[i-1]+j)/2]+1)%100;
                ///tmp[h[i-1]+j]=a[i][j]%100;
            ///}
        ///}
    ///}
    a[x][1]=1;
    for(int i=x-1;i>=1;i--)
        for(int j=1;j<=x-i+1;j++)
            a[i][j]=(a[i+1][j]+a[i+1][j-1])%mod;
    for(int i=x;i>=1;i--)
    {
        for(int j=1;j<=x-i+1;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }

    int ans=(max(solve(x-1,1)+a[x-1][2],a[x-1][1]+solve(x-1,2))+a[x][1])%mod;
        dp[x][1]=ans;
    for(int i=x;i>=1;i--)
    {
        for(int j=1;j<=x-i+1;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }

    cout<<ans%mod;
    return 0;
}
