///C


#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
const int maxn=3e5+5;
int a[maxn];
vector<int> v;
main()
{
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    if(k>=n)
    {
        cout<<0;
        return 0;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i>1)
            v.push_back(-a[i]+a[i-1]),ans+=a[i]-a[i-1];
    }
    sort(v.begin(),v.end());
    for(int i=0;i<k-1;i++)
        ans+=v[i];
    cout<<ans;
}
