///Chefer


#include <bits/stdc++.h>

using namespace std;
const int maxn=1e6;
vector <int> v[maxn];
int d[maxn];
queue <int> q;
vector <int> ans;
main()
{
    int n;
    cin>>n;
    int t1,t2;
    int m;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>t1>>t2;
        v[t2].push_back(t1);
        d[t1]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(!d[i])
            q.push(i);
    }
    int x;
    while(q.size())
    {
        x=q.front();
        q.pop();
        ans.push_back(x);
        for(int i=0;i<v[x].size();i++)
        {
            d[v[x][i]]--;
            if(d[v[x][i]]==0)
                q.push(v[x][i]);
        }
    }
    for(int i=ans.size()-1;i>=0;i--)
        cout<<ans[i]<<" ";
    return 0;
}
