#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=10949;
int dp[1000009];

main()
{
    dp[1]=2;
    for(int i=2;i<=1000;i++)
    {
        int ret=1;
        int t=3;
        for(int j=0;j<=30;j++)
        {
            if((i-1)&(1<<j))
                ret=(ret*t)%mod;
            t=(t*t)%mod;
        }
        dp[i]=(dp[i-1]+2*(dp[i-1]+((ret*((1<<(i-1))%mod))%mod)))%mod;
    }
    int ret=1;
    for(int i=1;i<=3;i++)
        ret=(ret*dp[1000])%mod;
    cout<<dp[4]<<endl<<ret;
    return 0;
}
