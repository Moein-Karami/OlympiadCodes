///Chefer


#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int ans[maxn];
vector <int> v[maxn];
int a[maxn];
set<int>::iterator it;

set<int> tmp;
set<int> dfs(int p,int x)
{
    vector<set<int>> vs;
    int s=0;
    int maxi=0;
    int u=0;
    int t=0;
    bool c=0;
    for(int i=0;i<v[x].size();i++)
    {
        u=v[x][i];
        if(u==p)
            vs.push_back(tmp);
        if(u!=p)
        {
            c=1;
            vs.push_back(dfs(x,u));
            t=vs[i].size();
            if(t>maxi)
            {
                maxi=t;
                s=i;
            }
        }
    }
    if(!c)
    {
        ans[x]=1;
        set<int> answer;
        answer.insert(a[x]);
        return answer;
    }
    vs[s].insert(a[x]);
    for(int i=0;i<v[x].size();i++)
    {
        u=v[x][i];
        if(u!=p&&i!=s)
        {
            while(vs[i].size())
            {
                it=vs[i].begin();
                t=*it;
                vs[s].insert(t);
                vs[i].erase(t);
            }
        }
    }
    ans[x]=vs[s].size();
    return vs[s];
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n,m,r;
    cin>>n>>m>>r;
    for(int i=1;i<n;i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        v[t1].push_back(t2);
        v[t2].push_back(t1);
    }
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dfs(r,r);
    int t;
    for(int i=1;i<=m;i++)
    {
        cin>>t;
        cout<<ans[t]<<"\n";
    }
    return 0;
}
