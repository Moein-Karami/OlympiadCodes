#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod=10753;
int a[100];
int ans;
int solve(int x)
{
    int ret=0;
    if(x<=2)
        return 0;
    for(int i=20;i>=0;i--)
    {
        if((1<<i)<=x)
        {
            ret=(ret+a[i])%mod;
            ret=(ret+2*solve(x-(1<<i)))%mod;
            if(x!=(1<<i))
                ret++;
            return ret;
        }
    }
    return ret;
}
main()
{
    a[1]=0;
    for(int i=2;i<100;i++)
        a[i]=(3*a[i-1]+1)%mod;
    ans=solve(0LL+1020304055LL);
    cout<<ans<<" "<<(ans*ans)%mod;
    return 0;
}
