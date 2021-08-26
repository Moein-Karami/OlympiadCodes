#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll a[12];
ll inf=1e17;
ll dp[12][10100];
ll solve(int x,int y)
{
    if(dp[x][y])
        return dp[x][y];
    if(x==0)
    {
        if(y!=0)
            return -1;
        else
            return 0;
    }
    ll ret=inf;
    ll tmp;
    ll t;
    bool c=0;
    for(ll i=0;i<=sqrt(y);i++)
    {
        tmp=(a[x]-i)*(a[x]-i);
        t=solve(x-1,y-(i*i));
        if(t!=-1)
        {
            c=1;
            tmp+=t;
            ret=min(ret,tmp);
        }
    }
    if(!c)
        return dp[x][y]=-1;
    return dp[x][y]=ret;
}
int main()
{
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    ll ans=solve(n,m);
    cout<<ans;
    return 0;
}
