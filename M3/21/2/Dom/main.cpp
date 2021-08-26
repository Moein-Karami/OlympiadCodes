#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn=1e8,mod=10687;
int p[maxn+10];
main()
{
    for(int i=2;i<=maxn;i++)
        if(!p[i])
            for(int j=i;j<=maxn;j+=i)
                p[j]++;
    int ans=0;
    for(int i=2;i<=maxn;i++)
        if(p[i]==i%10)
            ans=(ans+i)%mod;
    cout<<ans;
    return 0;
}
