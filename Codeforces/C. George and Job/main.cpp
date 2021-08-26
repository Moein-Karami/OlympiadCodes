#include <iostream>
#include <algorithm>
//C. George and Job
//eslahi
using namespace std;
long long int a[5010],p[5010],dp[5010][5010];
int main()
{
    long long int n,m,k,maxi=0;
    cin>>n>>k>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        p[i]=p[i-1]+a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(k*j<=i)
            {
            dp[i][j]=max(dp[i-1][j],p[i]-p[i-k]+dp[i-k][j-1]);

            if(dp[i][j]>maxi)
                maxi=dp[i][j];
            }

            ///cout<<"<<"<<i<<","<<j<<","<<dp[i][j]<<">>"<<" ";
        }
        ///cout<<endl;
    }
    cout<<maxi;
    return 0;
}

