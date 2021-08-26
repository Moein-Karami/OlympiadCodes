#include <bits/stdc++.h>
#define int long long int
using namespace std;
int dp[999999];
int a[10000];
const int mod=11969;
int mabna(int x)
{
    for(int i=31;i>=0;i--)
        if((1<<i)<=x)
            return i;
}
int tavan(int x,int y)
{
    int ret=1;
    for(int i=0;i<=mabna(y);i++)
    {
        if(y&(1<<i))
            ret=(ret*x)%mod;
        x=(x*x)%mod;
    }
    return ret;
}
main()
{
    for(int i=1;i<=222222;i++)
        dp[i]=1000000000;
    dp[1]=1;
    a[1]=1;
    for(int i=2;i<=9999;i++)
        a[i]=a[i-1]+(i*(i+1))/2;
    for(int i=2;i<=222222;i++)
    {
        int j=1;
        while(a[j]<=i)
        {
            dp[i]=min(dp[i],1+dp[i-a[j]]);
            j++;
        }
    }
    int ans=0;
    for(int i=111111;i<=222222;i++)
        ans=(ans+(tavan(dp[i],i)%mod))%mod;
    cout<<ans;
    return 0;
}
