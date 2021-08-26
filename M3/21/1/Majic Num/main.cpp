#include <bits/stdc++.h>
#define int long long int
using namespace std;
int ans=1e12,mod=10487;
int p[11]={2,3,5,7,11,13,17,19,23,29,31};
void solve(int x,int y,int z,int k)
{
    if(y>=2011)
    {
        ans=min(ans,z);
        return;
    }
    int t=1;
    for(int i=1;i<=k;i++)
    {
        t*=p[x];
        if(t*z>ans)
            return;
        solve(x+1,y*(i+1),z*t,i);
    }
}
main()
{
    solve(0,1,1,10);
    cout<<ans<<" "<<ans%mod;
    return 0;
}
