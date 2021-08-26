///Chefer


#include <bits/stdc++.h>
#define int long long int
using namespace std;
int dp[1010],a[1010],s[1010];
main()
{
    int n,k;
    cin>>n>>k;
    s[0]=0;
    dp[0]=0;
    for(int i=1;i<=k;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }

    dp[1]=a[1];
    int mini=1e9;
    dp[2]=a[1]+a[2];
    for(int i=3;i<=k;i++)
    {
        mini=s[i]+dp[i-1];
        int tmp=a[i]+a[i-1],sum=a[i]+a[i-1];
        mini=min(mini,sum+s[i]+dp[i-2]);
        for(int j=i-2;j>=1;j--)
        {
            sum+=a[j];
            tmp=tmp+sum;
            mini=min(tmp+s[j-1]+dp[j-1],mini);
        }
        dp[i]=mini;
    }
    cout<<dp[k];
    return 0;
}
