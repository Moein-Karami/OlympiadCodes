///Chefer



#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
pii a[5010];
int ans[5010];
set <int> s;
main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<k;i++)
        cin>>a[i].f,a[i].s=i;
    sort(a,a+k);
    int cnt=0,cont=0;
    if(a[0].f==1)
    {
        cnt++;
        cont++;
        ans[a[0].s]=1;
    }
    s.insert(2);
    int tmp,t;
    set<int>::iterator x;
    for(int i=2;i<=n;i++)
    {
        t=i;
        tmp=i;
        while(tmp)
        {
            t+=tmp%10;
            tmp/=10;
        }
        s.insert(t);
        while((*(s.begin()))<i)
        {
            s.erase((*(s.begin())));
        }
        if((*(s.begin()))!=i)
        {
            cont++;
            if(cont==a[cnt].f)
            {
                ans[a[cnt].s]=i;
                cnt++;
            }
        }
    }
    cout<<cont<<endl;
    for(int i=0;i<k;i++)
        cout<<ans[i]<<" ";
    return 0;
}
