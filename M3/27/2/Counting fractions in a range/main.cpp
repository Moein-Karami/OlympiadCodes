#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
vector<pii> v;
bool cmp(pii a,pii b)
{
    return ((a.f*b.s)<(a.s*b.f));
}
main()
{
    int n;
    cin>>n;
    int ans=0;
    pii t1=pii(1,3),t2=pii(1,2),tmp;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(__gcd(i,j)==1)
            {
                tmp=pii(j,i);
                if(cmp(t1,tmp)&&cmp(tmp,t2))
                    ans++;
            }
        }
        cerr<<i<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
