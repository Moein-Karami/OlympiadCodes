///DARK PROGRAMMER



#include <bits/stdc++.h>
#define f first;
#define s second
using namespace std;

vector <int> v[100000];
queue <int> q;
bool b[100000];
int ans[100000];

int main()
{
    int n,m;
    cin>>n>>m;
    int a,c;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>c;
        v[c].push_back(a);
        v[a].push_back(c);
    }
    int s;
    cin>>s;
    ans[s]=0;
    q.push(s);
    b[s]=1;
    while(q.size())
    {
        int t=q.front();
        for(int i=0;i<v[t].size();i++)
        {
            if(!b[v[t][i]])
            {
                b[v[t][i]]=1;
                ans[v[t][i]]=ans[t]+1;
                q.push(v[t][i]);
            }
        }
        q.pop();
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    return 0;
}
