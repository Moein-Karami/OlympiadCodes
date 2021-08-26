///Chefer


#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn=100;
int a[maxn][maxn];
int r[maxn];
int c[maxn];
int ans;
main()
{
    int n,m;
    cin>>n>>m;
    ans+=n*m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            if(a[i][j])
                r[i]++;
    }
    for(int j=1;j<=m;j++)
        for(int i=1;i<=n;i++)
            if(a[i][j])
                c[j]++;
     for(int i=1;i<=n;i++)
     {
         ans+=(1LL<<r[i])+(1LL<<(m-r[i]));
         ans-=(m+2);
     }
     for(int i=1;i<=m;i++)
     {
         ans+=(1LL<<c[i])+(1LL<<(n-c[i]));
         ans-=(n+2);
     }
     cout<<ans;
    return 0;
}
