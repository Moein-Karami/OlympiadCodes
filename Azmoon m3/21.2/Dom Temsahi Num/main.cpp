#include <bits/stdc++.h>
#define int long long int

using namespace std;
const int mod=10687;
int ans;
int dp[110000000];
main()
{
    for(int i=2;i<100000000;i++)
    {
        if(!dp[i])
        {
            for(int j=i;j<100000000;j+=i)
                dp[j]++;
        }
    }
    for(int i=2;i<100000000;i++)
    {
        if(i%10==dp[i])
        {
            ans=(ans+i)%mod;
        }
    }

    cout<<ans;
    return 0;
}
