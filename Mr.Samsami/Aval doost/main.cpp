#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod=1e9+1;
bool b[100];
int c[100][100];
main()
{
    c[0][0]=1;
    for(int i=1;i<=46;i++)
        c[i][0]=1;
    for(int i=1;i<=46;i++)
    {
        for(int j=1;j<=i;j++)
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
    }
    b[1]=1;
    for(int i=2;i<=50;i++)
    {
        for(int j=2;j*j<=i;j++)
            if(i%j==0)
                b[i]=1;
    }
    int ans=0;
    for(int i=2;i<=45;i++)
    {
        if(!b[i])
        {
            ans+=c[45][i];
            ans%=mod;
        }

    }
    cout<<ans;
    return 0;
}
