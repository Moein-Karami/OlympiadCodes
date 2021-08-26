#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn=2e4+4,inf=1e5,mod=10631;
int a[maxn];
int solve(int x,int y)
{
    if(x==y)
        return 1;
    else if(x>y)
        return 0;
    int maxi=0;
    for(int i=x;i<=y;i++)
        maxi=max(maxi,a[i]);
    vector<int> v;
    v.push_back(x-1);
    for(int i=x;i<=y;i++)
        if(a[i]==maxi)
            v.push_back(i);
    int ret=1;
    v.push_back(y+1);
    for(int i=1;i<v.size();i++)
        ret+=solve(v[i-1]+1,v[i]-1);
    return ret;
}
main()
{
    int n=20000;
    a[1]=123;
    a[2]=456;
    for(int i=3;i<=n;i++)
        a[i]=(a[i-1]+a[i-2])%1234+1;
    int x=solve(1,n);
    x=(x*x)%mod;
    cout<<(x*x)%mod;
    return 0;
}
