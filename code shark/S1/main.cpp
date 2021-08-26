#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod=22943;
int dp[110][110];
int solve(int x,int y)
{

    if(x>100||x<1||y>100||y<1)
        return 0;
    if(x==1&&y==1)
        return 1;
    if(dp[x][y])
        return dp[x][y];
    int &ret=dp[x][y];
    if((x+y-1)%5!=0)
        ret+=((solve(x-1,y)+solve(x,y-1))%mod);
    if((x+y-2)%5==0)
        ret+=((solve(x-2,y)+solve(x,y-2)+solve(x-1,y-1))%mod);
    return ret;
}
main()
{
    cout<<solve(100,100);
    return 0;
}
