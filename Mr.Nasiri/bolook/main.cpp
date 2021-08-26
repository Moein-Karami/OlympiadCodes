#include <iostream>
#include <algorithm>
//eslahi
using namespace std;
int dp[1000000];
int arr[1000000];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    int cnt=1,sum=0;
    for(int i=1;i<=n;i++)
    {
        if(arr[i]+dp[cnt]>=0)
        {
            dp[cnt]=dp[cnt-1]+arr[i];
        }
        else
        {
            cnt++;
        }
    }
    int max1=0,max2=0;

    for(int i=1;i<=cnt;i++)
    {
        if(dp[i]>max1)
        {
            max2=max1;
            max1=dp[i];
        }
        else if(dp[i]>max2)
            max2=dp[i];
    }
    cout<<max1+max2;
    return 0;
}
