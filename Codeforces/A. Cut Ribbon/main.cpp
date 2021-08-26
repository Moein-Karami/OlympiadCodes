#include <iostream>
#include <algorithm>
using namespace std;
int dp[5000][4],a[4];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=3;i++)
        cin>>a[i];
    sort(a+1,a+4);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(dp[i][j-1]>0)
                dp[i][j]=max(dp[i][j-1],dp[i][j]);
            if(i>=a[j])
            {
                if(dp[i-a[j]][j])
                dp[i][j]=max(dp[i-a[j]][j]+1,dp[i][j]);
            if(i-a[j]==0)
                dp[i][j]=max(1,dp[i][j]);
            }

           // cout<<dp[i][j]<<" ";
        }
        //cout<<endl;
    }
    cout<<dp[n][3];
    return 0;
}
