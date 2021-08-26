///Return


#include <bits/stdc++.h>
#define f first
#define s second
#define vs v.size()
using namespace std;
typedef pair<int,int> pii;
const int maxn=1e5+5;
vector<pii> v;
int main()
{
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    int l,r,t1,t2;
    cin>>l>>r;
    v.push_back(pii(l,r));
    for(int i=2;i<=n;i++)
    {
        cin>>t1>>t2;
        if(t1==r+1)
            v[vs-1].s=t2;
        else
            v.push_back(pii(t1,t2));
        r=t2;
    }
    int ans=0;
    int tmp;
    for(int i=0;i<vs;i++)
    {
        t1=v[i].f;
        t2=v[i].s;
        t1+=k-1;
        if(t1>t2)
            continue;
        t2-=k-1;
        if(t1>t2)
        {
            ans++;
            continue;
        }
        tmp=t2-t1+1;
        ans+=tmp/k+(tmp%k!=0);
    }
    cout<<ans<<" "<<(m-1)/k;
    return 0;
}
