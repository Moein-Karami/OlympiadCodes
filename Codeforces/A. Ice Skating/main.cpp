///DARK PROGRAMMER



#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
pii vertex[110];
vector <int> v[110];
bool b[110];
void dfs(int x)
{
    for(int i=0;i<v[x].size();i++)
    {
        if(!b[v[x][i]])
        {
            b[v[x][i]]=1;
            dfs(v[x][i]);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>vertex[i].f>>vertex[i].s;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j!=i)
            {
                if(vertex[i].f==vertex[j].f||vertex[i].s==vertex[j].s)
                {
                    v[i].push_back(j);
                }
            }
        }
    }
    b[1]=1;
    dfs(1);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(!b[i])
        {
            ans++;
            dfs(i);
        }
    }
    cout<<ans;
    return 0;
}
