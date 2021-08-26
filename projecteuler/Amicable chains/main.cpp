#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn=1e6+6;
bool b[maxn];
int v[maxn];
int d[maxn];
bool mark[maxn];
main()
{
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        v[i]=1;
        for(int j=2;j*j<=i;j++)
        {
            if(i%j==0)
            {
                v[i]+=j;
                if(j*j!=i)
                    v[i]+=i/j;
            }
        }
        if(v[i]>n)
            b[i]=1;
        else
            d[v[i]]++;
    }
    queue<int> q;
    for(int i=2;i<=n;i++)
        if(!b[i]&&d[i]==0)
            q.push(i);
    while(q.size())
    {
        int x=q.front();
        q.pop();
        b[x]=1;
        if(v[x]>n||v[x]==1)
            continue;
        d[v[x]]--;
        if(d[v[x]]==0)
            q.push(v[x]);
    }
    //for(int i=2;i<=n;i++)
      //  cerr<<"I : "<<i<<" "<<b[i]<<endl;
    int ans=n,x=0,cnt=0,t=n;
    for(int i=2;i<=n;i++)
    {
        if(!b[i]&&!mark[i])
        {
            cnt=0;
            t=n;
            int ex=i;
            while(!mark[ex])
            {
                mark[ex]=1;
                cnt++;
                t=min(t,ex);
                ex=v[ex];
            }
            if(x<cnt)
            {
                x=cnt;
                ans=t;
            }
        }
    }
    cout<<ans;
    return 0;
}
