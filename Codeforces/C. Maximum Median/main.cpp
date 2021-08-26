///C


#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
const int maxn=2e5+5;
int a[maxn];
pii cnt[maxn];
main()
{
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    int p=0;
    for(int i=n/2+1;i<=n;i++)
    {
        if(a[i]!=a[i-1]||i==n/2+1)
            p++;
        cnt[p].f++;
        cnt[p].s=a[i];
    }
    int s=0;
    for(int i=1;i<=p;i++)
    {
        s+=cnt[i].f;
        if(i==p)
        {
            cout<<cnt[i].s+k/s;
            return 0;
        }
        else if(s*(cnt[i+1].s-cnt[i].s)>k)
        {
            cout<<cnt[i].s+k/s;
            return 0;
        }
        else
            k-=s*(cnt[i+1].s-cnt[i].s);
    }
}
