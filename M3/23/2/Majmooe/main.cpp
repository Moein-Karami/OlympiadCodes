#include <iostream>
using namespace std;
int mod=10711;
int dp[3][1010][1010];
int main()
{
    int ans=0;
    dp[0][0][0]=1;
    for(int i=1;i<=1000;i++)
    {
        int x=i%2;
        for(int j=0;j<=i;j++)
        {
            if(j==0)
            {
                dp[x][0][0]=1;
                continue;
            }
            for(int k=0;k<=j;k++)
            {
                dp[x][j][k]=(dp[1-x][j][k]+3*dp[1-x][j-1][k])%mod;
                if(k)
                    dp[x][j][k]=(dp[x][j][k]+dp[1-x][j-1][k-1])%mod;
            }
        }
    }
    for(int i=200;i<=800;i++)
        for(int j=200;j<=i;j++)
            ans=(ans+dp[0][i][j])%mod;
    cout<<ans;
    return 0;
}
