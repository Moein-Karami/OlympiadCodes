#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
vector <pii> v[1000];
int a[1000][1000];
int ans[1000];
bool b[1000];
main()
{
    int n,m;
    cin>>n>>m;
    int a,c,w;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>c>>w;
        v[a].push_back(pii(c,w));
        v[c].push_back(pii(a,w));
    }
    for(int i=2;i<=1000;i++)
        ans[i]=1e9;
    int mini;
    for(int i=0;i<v[1].size();i++)
    {
        ans[v[1][i].f]=v[1][i].s;
    }
    b[1]=1;
    for(int i=2;i<=n;i++)
    {
        mini=999;
        for(int j=2;j<=n;j++)
        {
            if(!b[j]&&ans[mini]>ans[j])
                mini=j;
        }
        b[mini]=1;
        for(int j=0;j<v[mini].size();j++)
        {
            ans[v[mini][j].f]=min(ans[v[mini][j].f],v[mini][j].s+ans[mini]);
        }
    }
    for(int i=2;i<=n;i++)
        cout<<i<<" : "<<ans[i]<<endl;
    return 0;
}
