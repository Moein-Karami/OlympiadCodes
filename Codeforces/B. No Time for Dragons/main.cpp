///hefer


#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
typedef pair <int,pii> pip;
const int maxn=1e6;
pip a[maxn];
main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].s.s>>a[i].s.f;
        a[i].f=a[i].s.f-a[i].s.s;
    }
    sort(a,a+n);
    int ans=0,tmp=0;
    ans=a[0].s.s;
    tmp=a[0].s.s-a[0].s.f;
    for(int i=1;i<n;i++)
    {
        if(a[i].s.s>tmp)
        {
            ans+=a[i].s.s-tmp;
            tmp=a[i].s.s-a[i].s.f;
        }
        else
            tmp-=a[i].s.f;
    }
    cout<<ans;
    return 0;
}
