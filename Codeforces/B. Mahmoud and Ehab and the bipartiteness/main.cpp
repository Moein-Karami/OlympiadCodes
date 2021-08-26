///Chefer


#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn=1e5+10;
int h[maxn];
vector <int> v[maxn];
int s[2];
void dfs(int p,int x)
{
    s[h[x]%2]++;
    for(int i=0;i<v[x].size();i++)
    {
        int u=v[x][i];
        if(u!=p)
        {
            h[u]=h[x]+1;
            dfs(x,u);
        }
    }
}
main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        v[t1].push_back(t2);
        v[t2].push_back(t1);
    }
    dfs(1,1);
    cout<<s[0]*s[1]-n+1LL;
    return 0;
}
