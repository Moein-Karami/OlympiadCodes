#include <bits/stdc++.h>
#define f first
#define s second
#define int long long int
using namespace std;
typedef pair<int,int>pii;
const int maxn=2e6,mod=12809,inf=1e9;
int a[maxn];
vector<pii> v[maxn];
int dp[maxn][30];
int p[maxn];
vector<int> t;
int solve(int x,int y)
{
    if(y<0)
        return inf;
    if(x==t.size()-1)
        return 0;
    if(x==t.size()-2)
        return min(y,t[x+1]);
    if(dp[x][y])
        return dp[x][y];
    dp[x][y]=inf;
    for(int i=0;i<=min(y,t[x+1]);i++)
        dp[x][y]=min(dp[x][y],i+solve(x+2,t[x+2]-(t[x+1]-i)));
    return dp[x][y];
}
main()
{
    for(int i=2;i<maxn;i++)
        if(!p[i])
            for(int j=i;j<maxn;j+=i)
                p[j]=i;
    int n,m;
    cin>>n>>m;
    a[1]=1426;
    for(int i=2;i<=n;i++)
        a[i]=1+(1394*a[i-1]+2015)%m;
    for(int i=1;i<=n;i++)
    {
        int te=a[i];
        int cnt=1;
        while(te>1)
        {
            if(p[te]!=p[te/p[te]])
            {
                v[p[te]].push_back(pii(i,cnt));
                cnt=0;
            }
            te/=p[te];
            cnt++;
        }
    }
    int ans=1;
    for(int i=1;i<=m;i++)
    {
        if(v[i].size())
        {
            t.push_back(v[i][0].s);
            int cnt=3;
            for(int j=1;j<v[i].size();j++)
            {
                if(v[i][j].f-1!=v[i][j-1].f)
                {
                    for(int k=0;k<=cnt;k++)
                        for(int q=0;q<=25;q++)
                            dp[k][q]=0;
                    ans=(ans+solve(0,t[0]))%mod;
                    t.clear();
                    cnt=3;
                }
                t.push_back(v[i][j].s);
                cnt++;
            }
            for(int k=0;k<=cnt;k++)
                for(int q=0;q<=25;q++)
                    dp[k][q]=0;
            ans=(ans+solve(0,t[0]))%mod;
            t.clear();
        }
    }
    cout<<ans;
    return 0;
}
