///DARK PROGRAMMER



#include <bits/stdc++.h>

using namespace std;
vector <int> v[1000000];
int max1[1000000],max2[1000000];
bool b[1000000];
int ans[1000000];
void dfs(int p,int x)
{
    int tmp;
    for(int i=0;i<v[x].size();i++)
    {
        if(!b[v[x][i]])
        {
            b[v[x][i]]=1;
            dfs(x,v[x][i]);
            if(max1[x]<=max1[v[x][i]])
            {
                max1[x]=max1[v[x][i]]+1;
                tmp=v[x][i];
            }
        }
    }
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i]!=p&&v[x][i]!=tmp&&max2[x]<=max1[v[x][i]])
        max2[x]=max1[v[x][i]]+1;
    }
}
void chefer(int p,int x)
{
    for(int i=0;i<v[x].size();i++)
    {

        if(v[x][i]!=p)
        {
            chefer(x,v[x][i]);
            ans[x]=max(ans[x],ans[v[x][i]]);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int a,c;
    for(int i=1;i<n;i++)
    {
       cin>>a>>c;
       v[a].push_back(c);
       v[c].push_back(a);
    }
    int root;
    cin>>root;
    b[root]=1;
    dfs(root,root);
    int q,t;
    cin>>t;
    for(int i=1;i<=n;i++)
        ans[i]=max1[i]+max2[i];
    chefer(root,root);

    for(int i=1;i<=t;i++)
    {
        cin>>q;
        cout<<ans[q]<<endl;
    }
    return 0;
}
