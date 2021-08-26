#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod=7;
int tavan [50];
vector <int> v;
int check(int x)
{
    for(int i=32;i>=0;i--)
        if(x>=(1<<i))
            return i;
}
main()
{
    int x;
    cin>>x;
    tavan[0]=x;
    for(int i=1;i<=33;i++)
        tavan[i]=(tavan[i-1]*tavan[i-1])%mod;
    for(int i=0;i<=check(x);i++)
    {
        if(x&(1<<i))
            v.push_back(1);

        else
            v.push_back(0);
    }
    int ans=1;
    for(int i=0;i<v.size();i++)
    {
        if(v[i])
            ans=(ans*tavan[i])%mod;
    }
    cout<<ans;
    return 0;
}
