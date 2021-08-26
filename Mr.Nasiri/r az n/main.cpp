#include <iostream>

using namespace std;
int dp[1000+100][1000+100];
int mod=1e9+7;
int main()
{
    int n,r;
    cin>>n>>r;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==i||j==0)
                dp[i][j]=1;
            else if(i==0)
                dp[i][j]==0;
            else
                dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%mod;
        }
    }
    cout<<dp[n][r];
    return 0;
}
