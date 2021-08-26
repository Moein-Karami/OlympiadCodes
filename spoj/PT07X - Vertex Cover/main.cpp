///DARK PROGRAMMER



#include <bits/stdc++.h>

using namespace std;
vector <int> v[100010];

int dp[100010][2];
void dfs(int p , int x)
{
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i]!=p)
        {
            dfs(x , v[x][i]);
            dp[x][0]+=dp[v[x][i]][1];
            dp[x][1]+=min(dp[v[x][i]][0],dp[v[x][i]][1]);
        }
    }
    dp[x][1]+=1;
}
int main()
{
    int n;
    cin>>n;
    int a,b;
    for(int i=1;i<n;i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(0,1);
    cout<<min(dp[1][1],dp[1][0]);
    return 0;
}
