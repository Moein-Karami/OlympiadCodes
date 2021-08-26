///Chefer


#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn=1e5+5;
vector <int> v[maxn];
int mark[maxn];
int kh[maxn];
void dfs(int x,int p)
{
    for(int i=0;i<v[x].size();i++)
    {
        int u=v[x][i];
        if(!mark[u])
        {
            mark[u]=p;
            kh[p]++;
            dfs(u,p);
        }
    }
}
main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int t1,t2,t3;
    int tmp;
    for(int i=1;i<n;i++)
    {
        cin>>t1>>t2>>t3;
        tmp=t3;
        bool b=0;
        while(tmp)
        {
            if(tmp%10!=4&&tmp%10!=7)
                b=1;
            tmp/=10;
        }
        if(b)
        {
            v[t1].push_back(t2);
            v[t2].push_back(t1);
        }
    }
    int cnt=1;
    for(int i=1;i<=n;i++)
    {
        if(!mark[i])
        {
            mark[i]=cnt;
            kh[cnt]++;
            dfs(i,cnt);
            cnt++;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int t=mark[i];
        int x=kh[t];
        int s=n-x;
        ans+=s*(s-1);
    }
    cout<<ans;
    return 0;
}
