#include <iostream>
#define int long long int
using namespace std;
const int mod=10711;
int a[mod*mod+10];
main()
{
    int ans=0;
    for(int i=1;i<mod;i++)
        for(int j=1;j<mod;j++)
            a[i*j]++;
    for(int i=1;i<mod;i++)
    {
        int t=1;
        while(i*t<mod*mod)
        {
            ans+=a[i*t];
            t++;
        }
    }
    cout<<ans<<" "<<ans%mod;
    return 0;
}
