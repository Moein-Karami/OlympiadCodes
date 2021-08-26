///Chefer


#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<double,int> pii;
const int maxn=1e5+5;
int a[maxn];
vector <int> v[maxn];
main()
{
    int n,k,t,val;
    cin>>n>>k;
    set <pii> se;
    for(int i=1;i<=k;i++)
        se.insert(pii(0,i));
    set<pii>::iterator x;
    for(int i=1;i<=n;i++)
    {
        x=se.begin();
        cin>>a[i];
        se.erase(*x);
        t=(*x).s;
        cout<<t<<" ";
        v[t].push_back(a[i]);
        int val=v[t].size();
        val--;
        if(v[t].size()==1)
            se.insert(pii(a[i],t));
        else{
                double d=(v[t][val]+v[t][val-1]),k=v[t].size();
                d/=2;
                double ans=d*k;
                se.insert(pii(ans,t));
            //cerr<<endl<<i<<" : DONE : "<<ans<<endl;
           // cerr<<endl<<t<<" : DONE : "<<((v[t][val]+v[t][val-1])/2)*v[t].size()<<endl;
        }
    }
    return 0;
}
