#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod=123456789;
int dp[100][100];
main()
{
    dp[1][1]=1;
    for(int i=1;i<=100;i++)
    {
        for(int j=1;j<=100;j++)
        {
            for(int q=0;q*i<=j;q++)
            {
                dp[i][j]=(dp[i][j]+q*((1LL<<i)-i)+dp[i-1][j-q*i])%mod;
            }

        }
    }
    return 0;
}
