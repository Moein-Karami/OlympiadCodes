#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=10487;
bool p[mod+10];
vector <int> v,num[mod+10],tnum[mod+10];
int dp[mod+10];
int solve(int x)
{
    if(dp[x])
        return dp[x];
    for(int i=x+1;i<mod;i++)
    {
        if(p[i]==0&&((x%10)==num[i][0]))
        {
            dp[x]=max(dp[x],solve(i)+num[x].size()-1);
        }
    }
    return dp[x];
}
main()
{
    for(int i=1;i<mod;i++)
    {
        int t=i;
        while(t)
        {
            tnum[i].push_back(t%10);
            t/=10;
        }
        for(int j=tnum[i].size()-1;j>=0;j--)
            num[i].push_back(tnum[i][j]);
    }
    for(int i=2;i<mod+10;i++)
    {
        if(!p[i])
        {
            for(int j=i*i;j<mod+10;j+=i)
                p[j]=1;
        }
    }
    for(int i=0;i<=7;i++)
        p[i]=1;
    int ans=0;
    for(int i=11;i<mod;i++)
        if(!p[i])
            ans=max(ans,solve(i)),cout<<solve(i)<<endl;
    cout<<ans<<endl<<(((ans*ans)%mod)*ans)%mod;
    return 0;
}
