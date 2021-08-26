#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn=2e3,mod=12809;
int c[maxn][maxn];
int gcd(int x,int y)
{
    while(x&&y)
    {
        if(x<y)
            swap(x,y);
        x%=y;
    }
    return max(x,y);
}
main()
{
    for(int i=0;i<maxn;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(i==j||j==0)
                c[i][j]=1;
            else
                c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
        }
    }
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i!=j)
                ans=(ans+c[n][i]*c[n][j]*gcd(i,j))%mod;
            else
                ans=(ans+c[n][i]*(c[n][j]-1)*i)%mod;
        }
    }
    for(int i=1;i<=mod-2;i++)
        ans=(ans*2)%mod;
    cout<<ans;
    return 0;
}
