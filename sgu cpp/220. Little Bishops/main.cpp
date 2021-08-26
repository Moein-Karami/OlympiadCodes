///Chefer


#include <bits/stdc++.h>
#define int long int
using namespace std;
bool r[50],c[50];
int n,k;
int dp[20][1<<19];
int solve(int x,int t,int mask)
{
    if(dp[x-2][mask]!=-1)
        return dp[x-2][mask];
    dp[x-2][mask]=0;
    int &ret=dp[x-2][mask];
    if(2*n-x+1<k-t)
        return ret=0 ;
    if(x>2*n)
        return ret=(t==k);
    if(t==k)
        return ret=1;
    if(x<=n+1)
    {
        for(int i=1;i<x;i++)
        {
            if(!c[i-(x-i)+n])
            {
                c[i-(x-i)+n]=1;
                ret+=solve(x+1,t+1,mask+(1<<(i-(x-i)+n-1)));
                c[i-(x-i)+n]=0;
            }
        }
    }
    else
    {
        for(int i=n;i>=x-n;i--)
        {
            if(!c[i-(x-i)+n])
            {
                c[i-(x-i)+n]=1;
                ret+=solve(x+1,t+1,mask+(1<<(i-(x-i)+n-1)));
                c[i-(x-i)+n]=0;
            }
        }
    }
    ret+=solve(x+1,t,mask);
    return ret;
}
main()
{
    for(int i=0;i<20;i++)
        for(int j=0;j<(1<<19);j++)
            dp[i][j]=-1;
    //return 0;
    cin>>n>>k;
    cout<<solve(2,0,0);
    return 0;
}
