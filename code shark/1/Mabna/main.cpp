#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=12263,maxn=20;
int dp[maxn][4];
vector<int>v;
int solve(int x,int y)
{
    if(x==v.size())
        return 0;
    if(dp[x][y]!=-1)
        return dp[x][y];
    dp[x][y]=solve(x+1,y);
    if(v[x]>=y)
        dp[x][y]+=solve(x+1,v[x])+1;
    return dp[x][y];
}
main()
{
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<20;j++)
            for(int k=0;k<4;k++)
                dp[j][k]=-1;
        int t=i;
        while(t)
        {
            v.push_back(t%3);
            t/=3;
        }
        reverse(v.begin(),v.end());
        ans=(ans+solve(0,0))%mod;
        v.clear();
    }

    cout<<ans;
    return 0;
}
