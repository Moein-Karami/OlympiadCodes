///Chefer


#include <bits/stdc++.h>
#define f first
#define s second
#define ret dp[x][y]
#define t[x] a[x].f.s
#define d[x] a[x].f.f
#define p[x] a[x].s.f
using namespace std;
typedef pair<int,pair<int,bool>> pib;
typedef pair<pair<int,int>,pair<int,int>> pii;
pii a[110];
pib dp[110][2040];
int n;
int solve(int x,int y)
{
    if(x>n)
        return 0;
    if(dp[x][y].f)
        return dp[x][y].f;
    if(y+a[x].f.s>=a[x].f.f)
    {
        ret.s.f=y;
        return ret.f=solve(x+1,y);
    }
    else
    {
        if(a[x].s.f+solve(x+1,y+a[x].f.s)>solve(x+1,y))
        {
            ret.s.s=1;
            ret.s.f=y+a[x].f.s;
            return ret.f=a[x].s.f+solve(x+1,y+a[x].f.s);
        }
        else
        {
            ret.s.f=y;
            return ret.f=solve(x+1,y);
        }
    }
}
main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].f.s>>a[i].f.f>>a[i].s.f,a[i].s.s=i;
    sort(a+1,a+n+1);
    cout<<solve(1,0)<<endl;
    vector <int> ans;
    int x=1,y=0;
    while(x<=n)
    {
        if(dp[x][y].s.s)
            ans.push_back(a[x].s.s);
        int t2=dp[x][y].s.f;
        x++;
        y=t2;
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    return 0;
}
