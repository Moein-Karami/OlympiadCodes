///Chefer


#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;
const int inf=1e9;
typedef pair<double,double> pii;
typedef pair<double,pii> pip;
pip a[60][60];
pii dp[60][60];
int n,m;
main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i!=j)
            {
                dp[i][j].s=inf;
                a[i][j].s.s=inf;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        int t1,t2,c,t;
        cin>>t1>>t2>>c>>t;
        a[t1][t2].f=1;
        a[t2][t1].f=-1;
        a[t1][t2].s.f=c;
        a[t1][t2].s.s=t;
        a[t2][t1].s.f=c;
        a[t2][t1].s.s=t;
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            for(int k=1;k<i;k++)
            {
                if(a[i][k].f==0)
                    continue;
                if(a[i][k].f==1)
                {
                    if(dp[i][j].f/dp[i][j].s<(a[i][k].s.f+dp[k][j].f)/(a[i][k].s.s+dp[k][j].s))
                    {
                        dp[i][j].f=(a[i][k].s.f+dp[k][j].f);
                        dp[i][j].s=a[i][k].s.s+dp[k][j].s;
                    }
                }
                else
                {
                    if(dp[j][i].f/dp[j][i].s<(a[k][i].s.f+dp[j][k].f)/(a[k][i].s.s+dp[j][k].s))
                    {
                        dp[j][i].f=a[k][i].s.f+dp[j][k].f;
                        dp[j][i].s=a[k][i].s.s+dp[j][k].s;
                    }
                }
            }
        }
        for(int j=1;j<i;j++)
        {
            for(int )
        }
    }
    return 0;
}
