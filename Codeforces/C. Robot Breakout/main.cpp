///C


#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
int inf=1e5;
main()
{
    ios_base::sync_with_stdio(false);
    int Q;
    cin>>Q;
    for(int T=1;T<=Q;T++)
    {
        int n;
        cin>>n;
        int x,y,u=inf,d=-inf,l=-inf,r=inf;
        bool L,R,U,D;
        for(int i=1;i<=n;i++)
        {
            cin>>x>>y>>L>>U>>R>>D;
            if(!L)
                l=max(l,x);
            if(!R)
                r=min(x,r);
            if(!U)
                u=min(y,u);
            if(!D)
                d=max(y,d);
        }
        if(l>r||d>u)
            cout<<"0\n";
        else
            cout<<1<<" "<<l<<" "<<d<<"\n";
    }
}
