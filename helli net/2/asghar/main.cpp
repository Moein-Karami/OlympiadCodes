///Expert



#include <iostream>
#define int long long int
using namespace std;
const int maxn=1010,mod=1e9+7;
int dp[maxn][maxn];
int a[maxn];
main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=3;i<=n;i++)
    {
        for(int j=2;j<i;j++)
        {
            for(int k=1;k<j;k++)
            {
                if(a[j]+a[k]==a[i])
                    dp[i][j]=(dp[i][j]+dp[j][k]+1)%mod;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=2;j<i;j++)
            ans=(ans+dp[i][j])%mod;
        cout<<ans;
    return 0;
}
