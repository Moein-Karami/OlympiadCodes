#include <iostream>

using namespace std;
int dp[100000];
int main()
{
    int n,m;
    cin>>n>>m;
    if(m>n)
    {
        cout<<-1;
        return 0;
    }
    for(int i=0;i<=n/2;i++)
    {
        if((i+(n-(i*2)))%m==0)
        dp[i]=i+(n-(i*2));
    }
    int mini=1e9;

    for(int i=0;i<=n/2;i++)
    {
        if(dp[i]!=0&&dp[i]<mini)
            mini=dp[i];
    }
    if(mini!=1e9)
        cout<<mini;
    else
        cout<<-1;
    return 0;
}
