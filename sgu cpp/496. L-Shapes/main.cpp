#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<double,double>pii;
pii a[5050][2];
int ans;
double t(double x)
{
    return x*x;
}
double solve(int x)
{
    return t(a[x][0].f-a[x][1].f)+t(a[x][0].s-a[x][1].s);
}
main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=1;j++)
            cin>>a[i][j].f>>a[i][j].s;
        for(int j=1;j<i;j++)
        {
            for(int k=0;k<=1;k++)
            {
                for(int l=0;l<=1;l++)
                {
                    if(a[i][k].f==a[j][l].f&&a[i][k].s==a[j][l].s)
                    {
                        if(solve(i)+solve(j)==t(a[i][1-k].f-a[j][1-l].f)+t(a[i][1-k].s-a[j][1-l].s))
                            ans++;
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
