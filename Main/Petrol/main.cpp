#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
const int maxn=1e6+6;
int ans[maxn];
int d[maxn];
set<pii> se;
int main()
{
    ios_base::sync_with_stdio(false);
    int t,n;
    cin>>t>>n;
    n++;
    int t1,t2;
    int x=0;
    set<pii> :: iterator it;
    pii tmp;
    for(int i=1;i<=n;i++)
    {
        if(i!=1)
        {
            it=se.begin();
            while((*it).s+t<x)
            {
                se.erase(it);
                it=se.begin();
            }
            tmp=*it;
            ans[i]=ans[i-1]+(d[i]-d[i-1])*tmp.f;
        }
        if(i!=n)
        {
            cin>>t1>>t2;
            se.insert(pii(t1,x));
            x+=t2;
            d[i+1]=x;
        }
    }
    cout<<ans[n];
    return 0;
}
