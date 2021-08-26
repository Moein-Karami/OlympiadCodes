#include <bits/stdc++.h>
#define int long long int
using namespace std;
int dp[12][12][1<<12][50];
int n,k;
int solve(int i,int j,int mask,int x)
{
    if(j>n)
    {
        j=1;
        i++;
    }
    if(x>k)
        return 0;
    int &ret=dp[i][j][mask][x];
    if(ret!=0)
        return ret;
    if(i==n+1)
        return (x==k);
    if(j==1)
    {
        if(!((1<<(n-1))&mask)&&!((1<<(n-2))&mask))
            ret=solve(i,j+1,((mask&((1<<n)-1))<<1)||1,x+1)+solve(i,j+1,((mask&((1<<n)-1))<<1),x);
        else
            ret=solve(i,j+1,((mask&((1<<n)-1))<<1),x);
    }
    else
    {
        if(!((1<<(n-1))&mask)&&!((1<<(n-2))&mask)&&!((1<<(n))&mask)&&!(1&mask))
            ret=solve(i,j+1,((mask&((1<<n)-1))<<1)||1,x+1)+solve(i,j+1,((mask&((1<<n)-1))<<1),x);
        else
            ret=solve(i,j+1,((mask&((1<<n)-1))<<1),x);
    }
    return ret;
}
main()
{
    cin>>n>>k;
    cout<<solve(1,1,0,0);
    return 0;
}
