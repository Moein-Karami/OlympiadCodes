///Chefer


#include <bits/stdc++.h>

using namespace std;
const int maxn=111;
vector <int> v[111],ans;
int s[maxn];
set <int> se;
main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x;
        cin>>x;
        int q;
        cin>>q;
        s[x]+=q;
        for(int j=1;j<=q;j++)
        {
            int t;
            cin>>t;
            v[t].push_back(x);
        }
    }
    for(int i=1;i<=n;i++)
        if(s[i]==0)
            se.insert(i);
    set<int>::iterator t;
    while(se.size())
    {
        t=se.begin();
        se.erase(*t);
        int x=*t;
        for(int i=0;i<v[x].size();i++)
        {
            s[v[x][i]]--;
            if(s[v[x][i]]==0)
                se.insert(v[x][i]);
        }
        ans.push_back(x);
    }
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    return 0;
}
