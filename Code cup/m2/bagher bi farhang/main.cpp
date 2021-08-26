#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int,pair<int,int>> pii;
const int maxn=200;
pii a[maxn];
int main()
{
    int n,l;
    cin>>n>>l;
    for(int i=0;i<n;i++)
        cin>>a[i].f>>a[i].s.f>>a[i].s.s;
    sort(a,a+n);
    int ans=0;
    int cnt=0;
    for(int i=1;i<=l;i++)
    {
        ans++;
        if(i==a[cnt].f)
        {
            //cerr<<"FUCK"<<endl;
            int t=ans%(a[cnt].s.f+a[cnt].s.s);
            //cerr<<t<<" "<<a[i].s.f<<endl;
            if(a[cnt].s.f>t)
                ans+=a[cnt].s.f-t;
            cnt++;
        }
        //cerr<<i<<" "<<ans<<endl;
    }
    cout<<ans;
    return 0;
}
