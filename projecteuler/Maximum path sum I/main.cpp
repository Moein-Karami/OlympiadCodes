#include <iostream>

using namespace std;
int a[17][17];
int dp[17][17];
int main()
{
    for(int i=2;i<=16;i++)
    {
        for(int j=1;j<=i-1;j++)
            cin>>a[j][i-j];
    }
    dp[1][1]=75;
    for(int i=3;i<=16;i++)
    {
        for(int j=1;j<=i-1;j++)
            dp[j][i-j]=max(dp[j-1][i-j],dp[j][i-j-1])+a[j][i-j];
    }
    int ans=0;
    for(int i=1;i<=15;i++)
        ans=max(ans,dp[i][16-i]);
    cout<<ans;
    return 0;
}
