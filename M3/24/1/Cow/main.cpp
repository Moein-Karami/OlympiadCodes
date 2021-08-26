#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn=1e6+6,mod=10631;
int maxi,mini;
int po[maxn];
int dp[maxn];
main()
{
    po[0]=1;
    for(int i=1;i<maxn;i++)
        po[i]=(po[i-1]*2)%mod;
    int n;
    cin>>n;
    for(int i=n;i>=1;i--)
        maxi=(maxi+po[i-1]*(po[i]-1)+po[i]*(po[n]-po[i])+mod)%mod;
    maxi=(maxi+po[n]-1)%mod;
    dp[1]=2;
    for(int i=2;i<=n;i++)
        dp[i]=(2*dp[i-1]+(po[i]-1)+(po[i]-1)*po[i-1])%mod;
    mini=dp[n];
    int x=(mini*maxi)%mod;
    cout<<mini<<" "<<maxi<<"   "<<(x*x)%mod;
    return 0;
}
