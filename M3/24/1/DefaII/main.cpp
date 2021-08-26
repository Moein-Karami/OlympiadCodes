#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=10631,maxn=2e4+4;
int p[10010][20002];
main()
{
    int n=20000,h=10000;
    for(int i=0;i<=h;i++)
    {
        p[i][0]=1;
        for(int j=1;j<=n;j++)
            p[i][j]=(p[i][j-1]*i)%mod;
    }
    int ans=p[h][n];
    for(int i=1;i<n;i++)
    {
        int x=n-i+1;
        x-=2;
        for(int j=1;j<h;j++)
        {
            ans=(ans+((x*(h-j)*(h-j))%mod)*((p[h][n-i-2]*(p[j][i]-p[j-1][i])%mod)))%mod;
            ans=(ans+((2*(h-j)*p[h][n-i-1])%mod)*(p[j][i]-p[j-1][i]))%mod;
        }
    }
    cout<<ans;
    return 0;
}
