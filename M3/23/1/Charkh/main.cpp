#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second

using namespace std;
typedef pair<int,int> pii;
const int mod=10357;
int a[5010][5010];
int e[5010*5010];
int dp[5010][5010];
int n;
int solve(int x,int y)
{
    if(dp[x][y])
        return dp[x][y];
    if(x==n)
        return dp[x][y]=a[x][y];
    return dp[x][y]=(a[x][y]+max(solve(x+1,y)+a[x+1][y+1],solve(x+1,y+1)+a[x+1][y]));
}
main()
{
    cin>>n;
    int cnt=0;
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
            cnt++;
            if(cnt==1)
                a[i][j]=mod%10;
            else
                a[i][j]=(e[cnt/2]+e[cnt-1]+1)%100;
            e[cnt]=a[i][j];
        }
    }
    cout<<solve(1,1)%mod;
    return 0;
}
