#include <iostream>
#include <algorithm>
//B.zuma
//eslahi

using namespace std;
int n;
int dp[510][510];
int a[1000];
int check(int ,int);
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    check(0,n-1);
    cout<<dp[0][n-1];

   return 0;
}

int check(int l,int r)
{
    if(dp[l][r])
        return dp[l][r];
    if(l==r)
        return dp[l][r]=1;
    if(l==r+1)
    {
        if(a[l]==a[r])
            return dp[l][r]=1;
        else
            return dp[l][r]=2;
    }
    dp[l][r]=5000;
    if(a[l]==a[r])
        dp[l][r]=check(l+1,r-1);

    for(int i=l;i<r;i++)
        dp[l][r]=min(dp[l][r],check(l,i)+check(i+1,r));
    return dp[l][r];
}
