///C


#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
const int maxn=5e3+10;
map<pii,int> mp;
vector<int> v[maxn];
int b[maxn],c;
int ans[maxn],cnt=1,p[maxn];
void dfs(int x)
{
    b[x]=c;
    for(int i=0;i<v[x].size();i++)
    {
        int u=v[x][i];
        if((b[u]!=0)&&(b[u]!=c))
        {
            ans[mp[pii(x,u)]]=1;
            continue;
        }
        else if(b[u]==0)
        {
            p[u]=x;
            ans[mp[pii(x,u)]]=1;
            dfs(u);
        }
        else
        {
            int t=x;
            while((t!=0)&&(t!=u))
                t=p[t];
            if(t==u)
            {
                cnt=2;
                ans[mp[pii(x,u)]]=2;
                //cout<<"SHIT : "<<mp[pii(x,u)]<<endl;
            }
            else
            {
                ans[mp[pii(x,u)]]=1;
            }
        }
    }
}
main()
{
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        v[t1].push_back(t2);
        mp[pii(t1,t2)]=i;
    }
    for(int i=1;i<=n;i++)
    {
        if(!b[i])
        {
            c++;
            dfs(i);
            //cout<<i<<endl;
        }
    }
    cout<<cnt<<endl;
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<" ";
}
