#include <iostream>
#define int long long int
using namespace std;
int dp[111][111];
int mod=1e9+7;
main()
{
    int ans=0;
    for(int i=0;i<=100;i++)
    {
        dp[i][0]=1;
    }
    for(int i=0;i<=100;i++)
    {
        for(int j=1;j<=100;j++)
        {
            if(j<=i)
            {
                dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
                if(dp[i][j]>=1000000)
                {
                    ans++;
                    dp[i][j]=1000001;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
