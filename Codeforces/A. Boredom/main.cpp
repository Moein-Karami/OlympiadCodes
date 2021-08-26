#include <iostream>

using namespace std;
long long int a[1000000] , dp[1000000] ,dp2[1000000];
int main()
{
    long long int n,ans=0,max1=0,max2=0;
    cin>>n;
    for(long long int i=0;i<n;i++)
    {
        cin>>a[i];
        dp[a[i]]++;
        if(a[i]>max1)
            max1=a[i];
    }

    for(long long int i=0;i<=max1;i++ )
    {
        dp[i]=i*dp[i];
    }
    dp2[-3]=0;
    dp2[-2]=0;
    dp2[-1]=0;
    dp2[0]=0;
    for(long long int i=0;i<=max1;i++)
    {
        dp2[i]=max(dp[i]+dp2[i-2],dp[i]+dp2[i-3]);
        if(dp2[i]>max2)
            max2=dp2[i];
    }
    cout<<max2;
    return 0;
}
