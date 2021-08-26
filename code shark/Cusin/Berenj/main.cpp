#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn=1e3+3,mod=12799;
int dp[maxn][maxn],ans[maxn];
int inf=100;
int solve(int x,int y,int z)
{
    if(y<=x)
        return 0;
    if(dp[x][y])
        return dp[x][y];
    y-=x;
    for(int i=1;i<=y;i++)
        dp[x][y+x]=max(dp[x][y+x],solve(x+1,y-i,z+i)+i*z);
    //cerr<<"X & Y : "<<x<<" "<<y+x<<" "<<dp[x][y]<<endl;
    return dp[x][y+x];
}
main()
{
    //cin >>inf;
    //cout<<(((inf-4)/2)*((inf-4)/2+1))%mod;
    for(int i=5;i<=100;i++)
    {
        for(int j=0;j<=i;j++)
            for(int k=0;k<=i;k++)
                dp[j][k]=0;
        ans[i]=solve(1,i,0)%mod;
        cout<<"I : "<<i-1<<" "<<ans[i-1]<<" "<<ans[i]-ans[i-1]<<endl;
    }
    return 0;
}
