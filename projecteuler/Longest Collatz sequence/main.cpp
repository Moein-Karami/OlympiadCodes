#include <bits/stdc++.h>
#define int long long int
using namespace std;
int dp[100000000];
int maxi,ans;
int solve(int x)
{
    if(x<1000000)
    {
        if(dp[x]>0)
            return dp[x];
        if(x%2==0)
            return dp[x]=1+solve(x/2);
        return dp[x]=1+solve(3*x+1);
    }
    else if(x%2==0)
        return solve(x/2)+1;
    return 1+solve(3*x+1);
}
main()
{
    dp[1]=1;
    for(int i=2;i<=1000000;i++)
    {
        if(maxi<solve(i))
        {
            ans=i;
            maxi=solve(i);
        }
    }
    cout<<ans;
    return 0;
}
