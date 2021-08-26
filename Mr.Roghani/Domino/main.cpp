///I'm Chefer ;)


#include <bits/stdc++.h>

using namespace std;
int dp[20][20][10000];
int n,m;
int solve(int i,int j,int mask)
{
    if(i==n+1&&j==m&&mask==(1<<10)-1)
        return 1;
    long long int ret;
    if(dp[i][j][mask])
        return dp[i][j][mask];
    if(i>1&&!(1<<9)&mask)
    {
        if(j==m)
            return dp[i+1][1][1||(((mask&(1<<9))-1)<<1)]=solve(i+1,1,1||(((mask&(1<<9))-1)<<1));
        else
            return dp[i][j+1][1||(((mask&(1<<9))-1)<<1)]=solve(i,j+1,1||(((mask&(1<<9))-1)<<1));
    }
    else
    {
        if(j==m)
        {
            if(!(1&mask))
            {
                dp[i+1][1]
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    long long int ans=solve(1,1,(1<<10)-1);
    return 0;
}
