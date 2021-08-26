///C


#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
const int maxn=3e5+5;
int dp[maxn],a[maxn];
main()
{
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    int ans=0;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        int s=0;
        for(int j=i;j>max(0LL,i-m);j--)
        {
            s+=a[j];
            dp[i]=max(dp[i],s-k);
        }
        if(i>m)
            dp[i]=max(dp[i],dp[i-m]+s-k);
        ans=max(ans,dp[i]);
    }
    cout<<ans;
}
