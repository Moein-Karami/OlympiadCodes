#include <iostream>
#define int long long int
using namespace std;
int mod=10009;
main()
{
    int ans=0;
    int x=mod*mod;
    while(x>1)
    {
        int t=0;
        while((1LL<<t)<=x)
            t++;
        t-=2;
        x-=2*(1LL<<t);
        ans=(ans+((1LL<<t)%mod)*((1LL<<t)%mod)*3)%mod;
    }
    cout<<ans;
    return 0;
}
