///Chefer


#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
const int maxn=1e3+3;
int a[maxn];
int ans[maxn];
main()
{
    int n,m,y;
    cin>>n>>m>>y;
    int t=0;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        ans[i]=(a[i]*m)/y;
        t+=ans[i];
    }
    t=m-t;
    for(int i=1;i<=n;i++)
    {
        if(t&&(a[i]*m)!=(ans[i]*y))
        {
            ans[i]++;
            t--;
        }
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    return 0;
}
