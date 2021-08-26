#include <iostream>

using namespace std;
int dp[200][200],a[200],s[200];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    int maxi=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
           dp[i][j]=(s[n]-s[j]+s[i-1])+(j-i+1)-(s[j]-s[i-1]);
           if(maxi<dp[i][j])
            maxi=dp[i][j];
        }
    }
    cout<<maxi;
    return 0;
}
