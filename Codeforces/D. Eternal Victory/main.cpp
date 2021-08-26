///DARK PROGRAMMER



#include <bits/stdc++.h>
#define f first
#define s second
#define int long long int
using namespace std;
typedef  pair<int,int>  pii;

const int maxn=1e5+10;
vector <pii> v[maxn];
int max1[maxn];
bool b[maxn];
void dfs(int x)
{
    for(int i=0;i<v[x].size();i++)
    {
        if(!b[v[x][i].f])
        {
            b[v[x][i].f]=1;
            dfs(v[x][i].f);
            max1[x]=max(max1[x],max1[v[x][i].f]+v[x][i].s);
        }
    }
}
main()
{
    int n;
    cin>>n;
    pii tmp;
    int a,c,w;
    int vazn=0;
    for(int i=1;i<n;i++)
    {
       cin>>a>>c>>w;
       tmp.f=a;
       tmp.s=w;
       v[c].push_back(pii(tmp));
       tmp.f=c;
       v[a].push_back(pii(tmp));
       vazn+=w;
    }
    vazn*=2;
    b[1]=1;
    dfs(1);
    cout<<vazn-max1[1];
    return 0;
}
