#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
const int mod=10357;
int po[mod];
int dp[mod];
main()
{
    po[0]=1;
    for(int i=1;i<mod;i++)
        po[i]=(po[i-1]*2)%mod;
    int x=po[10000]-1;
    x=x*po[9999];
    x%=mod;
    dp[0]=3;
    int ans=3;
    for(int i=1;i<10000;i++)
    {
        for(int j=i-1;j>=0;j--)
            dp[i]=(dp[i]+3*po[i-j-1]*dp[j])%mod;
        dp[i]=(dp[i]+3*po[i]);
        //cerr<<i<<" "<<dp[i];
        //getchar();
        ans=(ans+dp[i])%mod;
    }
    cout<<(ans*x)%mod;
    return 0;
}
