///Chefer


#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
const int maxn=1e5+5,inf=1e9+7;
int a[maxn],dp[maxn];
int binary(int l ,int r , int x)
{
    if(l+1==r)
        return l;
    int mid=(l+r)/2;
    if(dp[mid]>x)
        return binary(l,mid,x);
    else
        return binary(mid,r,x);
}
main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<maxn;i++)
        dp[i]=inf;
    for(int i=1;i<=n;i++)
    {
        int t=binary(0,maxn,a[i]);
        dp[t+1]=a[i];
    }
    for(int i=n;i>=1;i--)
    {
        if(dp[i]<inf)
        {
            cout<<i;
            return 0;
        }
    }
    return 0;
}
