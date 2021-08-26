#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=10607;
int ans=0;
int dp[100];
main()
{
    dp[1]=1;
    for(int i=2;i<50;i++)
    {
        dp[i]=(1LL<<(i-1));
        for(int j=1;j<i;j++)
            if(i%j==0)
                dp[i]-=dp[j];
    }
    for(int i=1;i<=48;i++)
    {
        for(int j=1;j<i;j++)
            if(i%j==0)
                ans+=dp[j];
    }
    int ret=1;
    for(int i=1;i<=mod;i++)
        ret=(ret*ans)%mod;
    cout<<ret;
    return 0;
}
