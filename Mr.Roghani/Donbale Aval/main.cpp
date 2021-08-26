#include <bits/stdc++.h>

using namespace std;
int n;
int a[101];
int dp[101][61];
bool b[61][61];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=60;i++)
    {
        for(int j=1;j<=60;j++)
        {
            int q=0;
            for(int w=2;w<=min(i,j);w++)
                if(i%w==0&&j%w==0)
                    q=1;
            b[i][j]=q;
        }
    }
    for(int i=1;i<=60;i++)
        dp[1][i]=fabs(a[i]-i);
    cout<<solve(2
    return 0;
}
