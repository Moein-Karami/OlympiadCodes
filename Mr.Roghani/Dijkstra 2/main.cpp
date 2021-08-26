#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int ,int > pii;
set <pii> se;
vector <pii> v[1000];
int val[1000];
main()
{
    int n,m;
    cin>>n>>m;
    se.insert(pii(0,1));
    for(int i=2;i<=n;i++)
        se.insert(pii(1e9,i)),val[i]=1e9;
    for(int i=1;i<=m;i++)
    {
        int c,t,w;
        cin>>c>>t>>w;
        v[c].push_back(pii(t,w));
        v[t].push_back(pii(c,w));
    }
    for(int i=1;i<=n;i++)
    {
        set<pii>::iterator x;
        x=se.begin();
        se.erase(*x);
        int t1=(*x).s;
        for(int j=0;j<v[t1].size();j++)
        {
            if(val[v[t1][j].f]>val[t1]+v[t1][j].s)
            {
                se.erase(pii(val[v[t1][j].f],v[t1][j].f));
                val[v[t1][j].f]=val[t1]+v[t1][j].s;
                se.insert(pii(val[t1]+v[t1][j].s,v[t1][j].f));
            }
        }
    }
    for(int i=2;i<=n;i++)
        cout<<i<<" : "<<val[i]<<endl;
    return 0;
}
