///C


#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
const int maxn=300;
vector<int> v[maxn];
int a[200000];
bool b[maxn];
int d[maxn],p[maxn];
main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(!a[i])
        {
            i--;
            n--;
        }
    }
    if(n>150)
    {
        cout<<3;
        return 0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if((a[i]&a[j])&&i!=j)
                v[i].push_back(j);
        }
    }
    int ans=maxn;
    for(int T=1;T<=n;T++)
    {
        queue<int> q;
        for(int i=1;i<maxn;i++)
            b[i]=0;
        b[T]=1;
        d[T]=0;
        p[T]=T;
        q.push(T);
        while(q.size())
        {
            int x=q.front();
            q.pop();
            for(int i=0;i<v[x].size();i++)
            {
                int u=v[x][i];
                if(!b[u])
                {
                    b[u]=1;
                    d[u]=d[x]+1;
                    p[u]=x;
                    q.push(u);
                }
                else if(u!=p[x])
                    ans=min(ans,d[u]+d[x]+1);
            }
        }
    }
    if(ans==maxn)
        ans=-1;
    cout<<ans;
}
