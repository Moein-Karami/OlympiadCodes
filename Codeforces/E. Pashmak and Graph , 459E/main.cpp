///DARK PROGRAMMER


#include <iostream>
#include <algorithm>
#include <stdio.h>
#define f first
#define s second
using namespace std;
int dp[1000000];
int dp2[1000000];
int x;
pair<int,pair<int , int > > g[1000000];
int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        scanf ("%d",&g[i].s.f);
        scanf ("%d",&g[i].s.s);
        scanf ("%d",&g[i].f);
    }
    sort(g,g+m);
    int k,j;
    for(int i=0;i<m;i++)
    {
        j=i;
        while(g[i].f==g[i+1].f)
        {
            i++;
        }
        k=i;
        for(int q=j;q<=k;q++)
        {
            dp2[g[q].s.f]=dp[g[q].s.f];
            dp2[g[q].s.s]=dp[g[q].s.s];
        }

        for(int q=j;q<=k;q++)
        {
            if(dp[g[q].s.f]+1>dp2[g[q].s.s])
            {
                dp2[g[q].s.s]=dp[g[q].s.f]+1;
            }
        }
        for(int q=j;q<=k;q++)
        {
            dp[g[q].s.f]=dp2[g[q].s.f];
            dp[g[q].s.s]=dp2[g[q].s.s];
        }
    }
    for(int i=0;i<=n;i++)
        x=max(x,dp[i]);
    cout<<x;
    return 0;
}
