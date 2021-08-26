#include <iostream>

using namespace std;
long long int dp[1000000],a[1000000];
int main()
{
    long long int f,n,k,tmp;
    f=10;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        dp[i]=dp[i-1]+a[i];
    }
    tmp=dp[n]+1000000;
    for(int i=k;i<=n;i++)
    {
        if(tmp>=dp[i]-dp[i-k])
        {

            tmp=dp[i]-dp[i-k];
        }
    }
    for(int i=k;i<=n;i++)
    {
        if(tmp==dp[i]-dp[i-k])
        {

            cout<<i-k+1;
            i=n+2;
        }

    }
    return 0;
}
