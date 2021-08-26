 #include <bits/stdc++.h>
#define int long long int
using namespace std;
int ans;
const int mod=22943;
int dp[51][2][5];
int solve(int i,int x,int y)
{
    x%=2;
    y%=5;
    if(y!=0&&x!=0)
        return 0;
    if(i==0)
        return 1;
    if(dp[i][x][y])
        return dp[i][x][y];
    int &ret=dp[i][x][y];
    for(int q=0;q<=2;q++)
        for(int w=0;w<=2;w++)
            if((x+q+w)%2==0||(y+q+w)%5==0)
                ret=(ret+solve(i-1,x+q+w,y+q+w))%mod;
    return ret;
}
main()
{
    for(int i=0;i<=2;i++)
        for(int j=0;j<=2;j++)
        if((i+j)%2==0)
            ans=(ans+solve(49,i+j,j+i))%mod;
    cout<<ans%mod;
    return 0;
}
