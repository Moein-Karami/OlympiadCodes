#include <bits/stdc++.h>
//#define int long long int
using namespace std;
const int maxn=1e6+6,mod=1e9+7,del=10567;
int dp[maxn][18][18];
int k;
int solve(int n,int x,int y,int e)
{
    //cerr<<n<<" "<<x<<" "<<y<<" "<<e<<endl;
    x%=k;
    e%=k;
    y%=k;
    if(x==0)
        x=1;
    if(e==0)
        e=k-1;
    if(dp[n][x][y])
        return dp[n][x][y];
    if(n==1)
        return dp[n][x][y]=(x*y)%k;
    return dp[n][x][y]=(solve(n-1,x+1,y*y*x,e)+solve(n-1,x,y*y*e,e-1))%mod;
}
main()
{
    int n;
    cin>>n>>k;
    int s1,s2;
    for(int i=1;i<=n-n/k;i++)
    {
        for(int x=1;x<17;x++)
        {
            //cerr<<"X : "<<i<<" "<<x<<endl;
            int e=(n-x)%k;
            if(e<=0)
                continue;
            for(int y=1;y<17;y++)
            {
                if(i==1)
                    dp[i][x][y]=(x*y)%k;
                s1=(x+1)%k;
                if(s1==0)
                    s1=1;
                dp[n][x][y]=(dp[i-1][s1][(y*y*x)%k]+dp[n-1][x][(y*y*e)%k])%mod;
            }
        }
    }
    cout<<dp[n-n/k][1][1]%del;
    return 0;
}
