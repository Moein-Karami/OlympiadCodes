#include <bits/stdc++.h>
#define int long long int
using namespace std;
int n;
int dpk[5000][5000],dpn[5000][5000];
int ans[5000];
const int mod=10513;
main()
{
    dpk[1][1]=1;
    dpn[1][1]=1;
    dpk[1][0]=1;
    dpn[1][0]=1;
    for(int i=2;i<=2014;i++)
    {
        dpk[i][0]=1;
        for(int j=1;j<=i;j++)
        {
            dpn[i][j]=dpk[i-1][j-1]%mod;
            dpk[i][j]=(dpn[i][j]+dpk[i-1][j])%mod;
        }
    }
    for(int i=2;i<=2014;i++)
    {
        ans[i]=(2*ans[i-1])%mod;
        for(int j=1;j<=i;j++)
            for(int k=0;k<j;k++)
                ans[i]=(ans[i]+dpn[i][k]*dpk[i-1][j])%mod;
    }
    cout<<ans[3]<<endl;
    int ret=1;
    for(int i=1;i<=2014;i++)
        ret=(ret*ans[2014])%mod;
    cout<<ret;
    return 0;
}
