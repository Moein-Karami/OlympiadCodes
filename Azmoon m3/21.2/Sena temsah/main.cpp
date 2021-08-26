#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=10687;
vector <int> v[696];
main()
{
    for(int i=1;i<=695;i+=2)
    {
        int t=i;
        while(t<=1390)
        {
            v[i].push_back(t);
            t*=2;
        }
    }
    int ans=1;
    for(int i=1;i<=695;i+=2)
        ans=(ans*v[i].size())%mod;
    cout<<ans;
    return 0;
}
