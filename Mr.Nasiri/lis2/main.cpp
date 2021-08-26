#include <iostream>

using namespace std;
int arr[1000+10];
int dp[1000+10];
int dp2[1000+10];
void lis(int,int ,int);
int main()
{
    int n,maxi=0;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for (int i=n-1;i>=0;i--)
    {
        dp[i]++;
        for(int j=i+1;j<n;j++)
        {

            if(arr[j]>=arr[i])
            {
                if(dp[i]<=dp[j])
                    dp[i]+=dp[j];
            }
        }
    }

    for(int i=0;i<n;i++)
        if(dp[i]>maxi)
        maxi=dp[i];
    for(int i=0;i<n;i++)
    {
        if(dp[i]==maxi)
        {
           dp2[i]++;
           lis(maxi,n,i);
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"  "<<dp2[i]<<endl;
    }
    return 0;
}
void lis(int maxi,int n ,int i)
{
    for(int j=i+1;j<n;j++)
    {
        if(maxi-dp[j]==1&&arr[i]<arr[j])
        {
            if(maxi!=1)
             lis(dp[j],n,j);
            dp2[j]++;
        }
    }

}
