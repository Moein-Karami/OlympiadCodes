#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=10559;
int ans;
main()
{
    int a1=1;
    int x;
    cin>>x;
    for(int i=1;i<=(x-1LL)*(x-1LL);i++)
        a1=(a1*2)%mod;
    ans+=a1;
    a1=1;
    for(int i=1;i<=x*x-2*x;i++)
        a1=(a1*2)%mod;
    ans=(ans+((x-1)%mod)*a1)%mod;
    cout<<ans;
    return 0;
}
