#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
int c[5010][5010];
int mod=10357;
int ans=1;
main()
{
    int n;
    cin>>n;
    c[0][0]=1;
    for(int i=1;i<=n-1;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(i==j||j==0)
                c[i][j]=1;
            else
                c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
        }
        if(i%2==1)
            ans=(ans+2*c[i][i/2])%mod;
        else ans=(ans+c[i][i/2]+c[i][i/2+1])%mod;
    }
    cout<<ans;
    return 0;
}
