///Chefer



#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
const int maxn=1e6,inf=1e12;
vector <pii> v[maxn];
int val[maxn];
int parent [maxn];
int n,m;
main()
{
    cin>>n>>m;
    int t1,t2,t3;
    for(int i=1;i<=m;i++)
    {
        cin>>t1>>t2>>t3;
        if(t1!=t2)
        {
            v[t1].push_back(pii(t2,t3));
            v[t2].push_back(pii(t1,t3));
        }

    }
    set <pii> se;
    for(int i=2;i<=n;i++)
        val[i]=inf;
    se.insert(pii(0,1));
    while(se.size())
    {
        int u=se.begin()->s;
        int V=se.begin()->f;
        se.erase(se.begin());
        //cout<<u<<" "<<V<<endl;
        for(int j=0;j<v[u].size();j++)
        {
            int t=v[u][j].f;
            int w=v[u][j].s;
          //  cout<<" "<<t<<' '<<w<<' '<<V<<' '<<val[t]<<endl;
            if(val[t]>V+w)
            {
                parent[t]=u;
                val[t]=V+w;
                se.insert(pii(val[t],t));
            }
        }
    }
    int ans=n;
    vector <int> answer;
    if(parent[n]==0)
    {
        cout<<-1;
        return 0;
    }
    while(ans)
    {
        answer.push_back(ans);
        ans=parent[ans];
    }
    for(int i=answer.size()-1;i>=0;i--)
        cout<<answer[i]<<" ";
    return 0;
}
