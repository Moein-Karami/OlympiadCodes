#include <bits/stdc++.h>
#define int long long int
using namespace std;
int r[20][20];
int a[20];
int dp[1<<19][19];
int n,m,k;
int solve(int mask,int x)
{
    int &ret=dp[mask][x];
    if(ret>=0)
        return ret;
    ret=0;
    if(mask==(1<<x))
        return ret=a[x];
    mask-=(1<<x);
    for(int i=0;i<n;i++)
    {
        if((1<<i)&mask)
        {
            ret=max(ret,solve(mask,i)+a[x]+r[i][x]);
        }
    }
    return ret;
}
main()
{
    cin>>n>>m>>k;
    for(int i=0;i<(1<<n);i++)
        for(int j=0;j<n;j++)
            dp[i][j]=-1;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int t1,t2;
    for(int i=1;i<=k;i++)
    {
        cin>>t1>>t2;
        t1--;
        t2--;
        cin>>r[t1][t2];
    }
    for(int i=0;i<n;i++)
        solve((1<<n)-1,i);
    int ans=0;
    for(int i=0;i<(1<<n);i++)
    {
        if(__builtin_popcount(i)==m)
        {
            for(int j=0;j<n;j++)
                if(i&(1<<j))
                    ans=max(ans,dp[i][j]);
        }
    }
    cout<<ans;
    return 0;
}
