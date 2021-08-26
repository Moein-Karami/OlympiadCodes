///Chefer


#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> pip;
const int maxn=2e5+10;
int a[maxn];
int cnt[10*maxn];
pip q[maxn];
int answer[maxn];
int ans;
int s;
bool cmp(pip A,pip B)
{
    if (A.f.f/s!=B.f.f/s)
        return A.f.f/s<B.f.f/s;
    return A.f.s>B.f.s;
}
main()
{
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    s=sqrt(n);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>q[i].f.f>>q[i].f.s,q[i].s=i;
    sort(q+1,q+m+1,cmp);
    int l=1,r=n;
    for(int i=1;i<=n;i++)
    {
        ans+=a[i]*(2*cnt[a[i]]+1);
        cnt[a[i]]++;
    }
    for(int i=1;i<=m;i++)
    {
        //cerr<<i<<endl;
        if(q[i].f.f<l)
        {
            for(int j=l-1;j>=q[i].f.f;j--)
            {
                ans+=a[j]*(2*cnt[a[j]]+1);
                cnt[a[j]]++;
            }
        }
        else if(q[i].f.f>l)
        {
            for(int j=l;j<q[i].f.f;j++)
            {
                ans-=a[j]*(2*cnt[a[j]]-1);
                cnt[a[j]]--;
            }
        }
        l=q[i].f.f;
        if(q[i].f.s>r)
        {
            for(int j=r+1;j<=q[i].f.s;j++)
            {
                ans+=a[j]*(2*cnt[a[j]]+1);
                cnt[a[j]]++;
            }
        }
        else if(q[i].f.s<r)
        {
            for(int j=r;j>q[i].f.s;j--)
            {
                ans-=a[j]*(2*cnt[a[j]]-1);
                cnt[a[j]]--;
            }
        }
        r=q[i].f.s;
        answer[q[i].s]=ans;
    }
    for(int i=1;i<=m;i++)
        cout<<answer[i]<<"\n";
    return 0;
}
