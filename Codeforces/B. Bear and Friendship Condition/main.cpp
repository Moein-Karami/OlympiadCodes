///DARK PROGRAMMER



#include <bits/stdc++.h>
#define int long long int
using namespace std;
vector <int> v[200000];
int a[200000];
int b[200000];
int n,m;
void dfs(int p,int x)
{
    a[p]=x;
    for(int i=0;i<v[p].size();i++)
        if(!a[v[p][i]])
            dfs(v[p][i],x);
}
main()
{
    cin>>n>>m;
    int c,r;
    for(int i=1;i<=m;i++)
    {
        cin>>c>>r;
        v[c].push_back(r);
        v[r].push_back(c);
    }
    int cnt=1;
    for(int i=1;i<=n;i++)
        if(!a[i])
            dfs(i,cnt),cnt++;
    for(int i=1;i<=n;i++)
    {
        b[a[i]]++;
    }
    int t=0;
    for(int i=1;i<=n;i++)
        t+=b[i]*(b[i]-1)/2;
    if(m==t)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
