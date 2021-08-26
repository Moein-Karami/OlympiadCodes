///Return


#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int,pair<int,int>> pii;
const int maxn=1e5+5;
pii a[maxn];
int Dv[maxn];
int Do[maxn];
int mark[maxn];
int kh[maxn];
void dfs(int x,int y)
{
    int u=a[x].s.f,v=a[x].s.s;
    if(dv)
}
main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].f;
    for(int i=1;i<=n;i++)
        cin>>a[i].s.f;
    for(int i=1;i<=n;i++)
        cin>>a[i].s.s;
    sort(a+1,a+n+1);
    cnt=1;
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
    return 0;
}
