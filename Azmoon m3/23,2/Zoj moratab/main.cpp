#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=10711;
int dp[mod*mod+10];
int ans;
main()
{
    dp[1]=1;
    for(int i=2;i<mod*mod;i++)
    {
        if(!dp[i])
        {
            for(int j=i;j<mod*mod;j+=i)
            {
                dp[j]=i;
            }
        }
    }
    int ret;
    int t;
    int s;
    for(int i=1;i<mod;i++)
    {
        for(int j=1;j<mod;j++)
        {
            ret=1;
            t=2;
            s=i*j;
            while(s!=1)
            {
                if(dp[s]==dp[s/dp[s]])
                    t++;
                else
                {
                    ret=(ret*t)%mod;
                    t=2;
                }
                s/=dp[s];
            }
            ret*=t;
            ans=(ans+ret)%mod;
        }
    }
    cout<<ans;
    return 0;
}
