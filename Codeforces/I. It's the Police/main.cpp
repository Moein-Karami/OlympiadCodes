///Chefer


#include <bits/stdc++.h>

using namespace std;
const int maxn=1e6;
vector <int>v[maxn];
int d[maxn];
bool b[maxn];
main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        d[i]=1;
    d[0]=maxn;
    int t1,t2;
    for(int i=1;i<=m;i++)
    {
        cin>>t1>>t2;
        v[t1].push_back(t2);
        v[t2].push_back(t1);
        d[t1]++;
        d[t2]++;
    }
    int mini=0;
    for(int i=1;i<=n;i++)
    {
        if(d[mini]>d[i])
            mini=i;
    }
    for(int i=0;i<v[mini].size();i++)
        b[v[mini][i]]=1;
    b[mini]=1;
    for(int i=1;i<=n;i++)
        cout<<1-b[i]<<" ";
    return 0;
}
