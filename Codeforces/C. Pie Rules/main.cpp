///Chefer


#include <bits/stdc++.h>

using namespace std;
int a[60];
int dp[60][2];
int n;
int inf=1e9;
int solve(int x,int y)
{
    if(x==n+1)
        return 0;
    if(dp[x][y])
        return dp[x][y];
    if(x==n)
    {
        if(y)
            return a[x];
        else
            return 0;
    }
    if(y)
    {
        int maxi=0;
        for(int i=x;i<=n;i++)
            maxi=max(a[i]+solve(i+1,0),maxi);
        return dp[x][y]=maxi;
    }
    int mini=inf;
    int s=0;
    for(int i=x;i<=n;i++)
    {
        mini=min(s+solve(i+1,1),mini);
        s+=a[i];
    }
    return dp[x][y]=mini;
}
main()
{
    cin>>n;
    int s=0;
    for(int i=1;i<=n;i++)
        cin>>a[i],s+=a[i];
    dp[1][1]=solve(1,1);
    cout<<s-dp[1][1]<<" "<<dp[1][1];
    return 0;
}
