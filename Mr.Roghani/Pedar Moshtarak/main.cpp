///Chefer


#include <bits/stdc++.h>

using namespace std;
const int maxn=2e5;
vector <int> v[maxn];
int p[maxn][30];
int h[maxn];
void dfs(int parent ,int x)
{
    h[x]=h[parent]+1;
    for(int i=0;i<v[x].size();i++)
    {
        if(!p[v[x][i]][0])
        {
            p[v[x][i]][0]=x;
            dfs(x,v[x][i]);
        }
    }
    for(int i=1;i<30;i++)
    {
        p[x][i]=p[p[x][i-1]][i-1];
    }
}
main()
{
    int n,q;
    cin>>n>>q;
    int t1,t2;
    for(int i=1;i<n;i++)
    {
        cin>>t1>>t2;
        v[t1].push_back(t2);
        v[t2].push_back(t1);
    }
    p[1][0]=1;
    dfs(1,1);

    for(int o=1;o<=q;o++)
    {
        cin>>t1>>t2;;
        if(h[t2]<h[t1])
            swap(t1,t2);

        for(int i=20;i>=0;i--)
            if(h[t2]-(1<<i)>=h[t1])
                t2=p[t2][i];
        //cerr<<"DONE"<<endl;
        if(t2==t1)
        {
            cout<<t1<<endl;
            continue ;
        }
        for(int i=20;i>=0;i--)
        {
            if(p[t1][i]!=p[t2][i])
            {
                t1=p[t1][i];
                t2=p[t2][i];
            }
        }
        cout<<p[t1][0]<<endl;
    }
    return 0;
}
