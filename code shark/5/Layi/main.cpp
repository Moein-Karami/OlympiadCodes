#include <bits/stdc++.h>
#define int long long int
using namespace std;
bool b[10][10];
int mod=10753;
int n;
bool solve(int x,int y)
{
    if(b[x][y])
       return 0;
    if(x==n-1&&y==n-1)
        return 1;
    return max(solve(x+1,y),solve(x,y+1));
}
main()
{
    cin>>n;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            if(j==n||i==n)
                b[i][j]=1;
    int ans=0;
    for(int i=0;i<(1<<(n*n));i++)
    {
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                b[j][k]=(i&(1<<(j*n+k)));
        ans+=solve(0,0);
    }
    cout<<ans%mod;
    return 0;
}
