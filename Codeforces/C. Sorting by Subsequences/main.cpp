///Chefer


#include <bits/stdc++.h>

using namespace std;
const int maxn=2e5;
int a[maxn];
int t[maxn];
map <int,int> mp;
vector <int> v[maxn],m[maxn];
bool b[maxn];
void dfs(int x,int cnt)
{
    for(int i=0;i<v[x].size();i++)
    {
        if(!b[v[x][i]])
        {
            m[cnt].push_back(v[x][i]);
            b[v[x][i]]=1;
            dfs(v[x][i],cnt);
        }
    }

}
main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        t[i]=a[i];
    }
    sort(t+1,t+1+n);
    for(int i=1;i<=n;i++)
    {
        if(!mp[t[i]])
            mp[t[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        v[i].push_back(mp[a[i]]);
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(!b[i])
        {
            cnt++;
            b[i]=1;
            m[cnt].push_back(i);
            dfs(i,cnt);
        }
    }
    cout<<cnt<<endl;
    for(int i=1;i<=cnt;i++)
    {
        cout<<m[i].size()<<" ";
        for(int j=0;j<m[i].size();j++)
            cout<<m[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
