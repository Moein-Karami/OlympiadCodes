///DARK PROGRRAMMER



#include <bits/stdc++.h>

using namespace std;
vector <int> v[1000000];
int mark[1000000];
void dfs(int x)
{
    for(int i=0;i<v[x].size();i++)
    {
        if(!mark[v[x][i]])
        {
           mark[v[x][i]]=mark[x];
           dfs(v[x][i]);
        }
    }
}
int main()
{
    int w;
    cin>>w;
    int n;
    int e;
    int a,b;
    for(int q=0;q<w;q++)
    {
        cin>>n;
        cin>>e;
        for(int i=0;i<n;i++)
        {
            mark[i]=0;
            v[i].resize(0);
        }
        for(int r=0;r<e;r++)
        {
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
          if(!mark[i])
          {
              ans++;
              mark[i]=ans;
              dfs(i);
          }
        }
        cout<<ans<<endl;
    }
    return 0;
}
