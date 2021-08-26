///DARK PROGRAMMER



#include <bits/stdc++.h>

using namespace std;
vector <int> v[100000];
bool b[100000];
int ans[100000];
int ans1[100000];
int dfs(int x,int p)
{
    b[x]=1;
    for(int i=0;i<v[x].size();i++)
    {
        if(!b[v[x][i]])
            dfs(v[x][i],x);
    }
    int max1=0,tmp;
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i]!=p&&ans[v[x][i]]>=max1)
            max1=ans[v[x][i]]+1,tmp=v[x][i];
    }
    ans[x]=max1;
    max1=0;
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i]!=p&&ans[v[x][i]]>=max1&&tmp!=v[x][i])
            max1=ans[v[x][i]]+1;
    }
    ans1[x]=max1;
}
int main()
{
    int n,a,c;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>a>>c;
        v[a].push_back(c);
        v[c].push_back(a);
    }
    b[1]=1;
    for(int i=0;i<v[1].size();i++)
    {
        if(!b[v[1][i]])
            dfs(v[1][i],1);
    }

    int max1=0,tmp;
    for(int i=0;i<v[1].size();i++)
    {
        if(ans[v[1][i]]>=max1)
            max1=ans[v[1][i]]+1,tmp=v[1][i];
    }
    ans[1]=max1;
    max1=0;
    for(int i=0;i<v[1].size();i++)
    {
        if(ans[v[1][i]]>=max1&&tmp!=v[1][i])
            max1=ans[v[1][i]]+1;
    }
    ans1[1]=max1;
    int j=0;
    for(int i=1;i<=n;i++)
    {
        tmp=max(ans[i],ans1[i]+ans[i]);
        j=max(tmp,j);
    }
    cout<<j;
    return 0;
}
