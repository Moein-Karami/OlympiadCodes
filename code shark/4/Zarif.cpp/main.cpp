#include <bits/stdc++.h>
#define int long long int

using namespace std;
const int maxn=3e5,mod=11969;
int a[maxn],dp[maxn];
int p(int x,int y)
{
    int ret=1;
    while(y)
    {
        if(y%2)
            ret=(ret*x)%mod;
        x=(x*x)%mod;
        y/=2;
    }
    return ret;
}
int solve(int x)
{
    if(dp[x]!=-1)
        return dp[x];
    if(x==0)
        return dp[x]=0;
    dp[x]=maxn;
    for(int i=1;a[i]<=x;i++)
        dp[x]=min(dp[x],solve(x-a[i])+1);
    return dp[x];
}
main()
{
    int cnt=1;
    a[1]=1;
    while(a[cnt]<maxn)
    {
        cnt++;
        a[cnt]=a[cnt-1]+cnt*(cnt+1)/2;
        //cerr<<cnt<<" "<<a[cnt]<<endl;
        //getchar();
    }
    for(int i=0;i<maxn;i++)
        dp[i]=-1;
    int l,r;
    cin>>l>>r;
    for(int i=1;i<=r;i++)
        solve(i);
    int ans=0;
    for(int i=l;i<=r;i++)
    {
        //cerr<<"I : "<<i<<" "<<solve(i)<<endl;
        ans=(ans+p(solve(i),i))%mod;
    }
    cout<<ans;
    return 0;
}
