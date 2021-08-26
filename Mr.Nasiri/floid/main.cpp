///DARK PROGRAMMER



#include <bits/stdc++.h>

using namespace std;
const int maxn=110;
int m[maxn][maxn];
int dp[maxn][maxn][2];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int z=0;z<2;z++)
                    dp[i][j][z]=1e9;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>m[i][j];
                dp[i][j][0]=m[i][j];
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j][k%2]=min(dp[i][j][k%2],min(dp[i][j][1-k%2],dp[i][k][1-k%2]+dp[k][j][1-k%2]));
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<i<<" "<<j<<" "<<dp[i][j][n%2];
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
