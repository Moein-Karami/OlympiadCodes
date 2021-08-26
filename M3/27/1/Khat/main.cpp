#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod=229939;
int dp[8][8][8][8][32];
int solve(int l0,int r0,int l1,int r1,int mask)
{
    int &ret=dp[l0][r0][l1][r1][mask];
    if(ret)
        return ret;
    ret=1;
    if(mask&1)
    {
        for(int i=l0+1;i<r0;i++)
        {
            if(i%2==1)
                ret=(ret+solve(l0,i,l1,r1,mask-1)*solve(i,r0,l1,r1,mask))%mod;
        }
    }
    if(mask&2)
    {
        for(int i=l1+1;i<r1;i++)
        {
            if(i%2==1)
                ret=(ret+solve(l0,r0,l1,i,mask-2)*solve(l0,r0,i,r1,mask))%mod;
        }
    }
    if(mask&4)
    {
        for(int i=l0+1;i<r0;i++)
        {
            if(i%2==0)
                ret=(ret+solve(l0,i,l1,r1,mask-4)*solve(i,r0,l1,r1,mask))%mod;
        }
    }
    if(mask&8)
    {
        for(int i=l1+1;i<r1;i++)
        {
            if(i%2==0)
                ret=(ret+solve(l0,r0,l1,i,mask-8)*solve(l0,r0,i,r1,mask))%mod;
        }
    }
    return ret;
}
main()
{
    cout<<solve(0,5,0,5,15);
    return 0;
}
