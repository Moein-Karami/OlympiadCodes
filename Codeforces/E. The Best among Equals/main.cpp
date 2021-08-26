///Chefer


#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
const int maxn=1e6;
pii a[maxn];
int n;
int ans[maxn];
main()
{
    int l=-1000000000;
    cin>>n;
    for(int i=0;i<2*n;i++)
    {
        a[i].s=1;
        cin>>a[i].f;
        i++;
        a[i].s=2;
        cin>>a[i].f;
    }
    sort(a,a+2*n);
    ans[0]=1;
    int maxi=1;
    for(int i=1;i<2*n;i++)
    {
        ans[i]=ans[i-1];
        if(a[i-1].s==2)
            ans[i]--;
        if(a[i].s==1)
            ans[i]++;
    }
    for(int i=2*n-1;i>=0;i--)
    {
        maxi=max(ans[i],maxi);
        if(a[i].s==1)
            break ;
    }
    cout<<maxi;
    return 0;
}
