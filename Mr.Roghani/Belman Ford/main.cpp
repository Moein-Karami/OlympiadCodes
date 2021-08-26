#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii ;
typedef pair<int,pii> pip ;
int val[1000];
pip e[250000];
main()
{
    int n,m;
    cin>>n>>m;

    int t1,t2,t3;
    for(int i=1;i<=m;i++)
    {
        cin>>t1>>t2>>t3;
        e[i].f=t3;
        e[i].s.f=t1;
        e[i].s.s=t2;
    }
    for(int i=2;i<=n;i++)
        val[i]=1e9;
    int u,v,w;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            u=e[j].s.f;
            v=e[j].s.s;
            w=e[j].f;
            if(val[v]>val[u]+w)
                val[v]=val[u]+w;
        }
    }
    for(int j=1;j<=m;j++)
    {
        u=e[j].s.f;
        v=e[j].s.s;
        w=e[j].f;
        if(val[v]>val[u]+w)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    for(int i=1;i<=n;i++)
        cout<<i<<" : "<<val[i]<<endl;
    return 0;
}
