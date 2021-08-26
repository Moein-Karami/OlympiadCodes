#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn=1e6+6,mod=10949;
int dp[maxn],po[maxn];
main()
{
    dp[1]=2;
    dp[2]=3;
    for(int i=3;i<maxn;i++)
        dp[i]=(dp[i-1]+dp[i-2])%mod;
    po[0]=1;
    for(int i=1;i<maxn;i++)
        po[i]=(po[i-1]*2)%mod;
    int n;
    cin>>n;
    int ans=0;
    for(int i=2;i<=n;i++)
    {
        int tmp=1;
        int x=0;
        for(int j=1;j<=n/i;j++)
        {
            if(j%i!=0)
            {
                int cnt=0;
                int t=j;
                while(t<=n)
                {
                    cnt++;
                    t*=i;
                }
                x+=cnt;
                tmp=(tmp*dp[cnt])%mod;
            }
        }
        //cerr<<"I : "<<i<<" "<<tmp<<endl;
        tmp=(tmp*po[n-x])%mod;
        ans=(ans+po[n]-tmp+mod)%mod;
    }
    cout<<ans;
    return 0;
}
