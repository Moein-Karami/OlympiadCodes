///Chefer


#include <bits/stdc++.h>
#define int long long int
using namespace std;
const in maxn=35005;
int dp[maxn][60];
int a[maxn];
int n,k;
int solve(int x,int y)
{
    if(dp[x][y])
        return dp[x][y];
    for(int i=x;i<=n;i++)
    {
        if()
    }
}
main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    set <int>s;
    for(int i=n;i>=1;i--)
    {
        s.insert(a[i]);
        dp[i][1]=s.size();
    }
    set <int> t;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(n-i<k-1)
            break;
        t.insert<a[i];
        ans=max(ans,solve(i+1,k-1));
    }
    cout<<ans;
    return 0;
}
