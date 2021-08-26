#include <bits/stdc++.h>

using namespace std;
typedef pair<string,bool> psb;
const int maxn=3e3+3;
int b[110][maxn];
bool in[maxn];
vector <int> v[maxn];
int n,m,o;
int dp[1010][2][2];
int dfs(int x,int y)
{
    if(x==-y)
        return 1;
    if(y<0)
        return b[x][y]=0;
    if(b[x][y]>-1)
        return b[x][y];
    return b[x][y]=dfs(x,v[y][0])^dfs(x,v[y][1]);
}
int solve(int i,string s,int j,int k)
{
    //cerr<<"I : "<<i<<" "<<j<<" "<<k<<endl;
    if(s.size()==i)
        return dp[i][j][k]=j;
    if(dp[i][j][k]!=-1)
        return dp[i][j][k];
    dp[i][j][k]=0;
    int &ret=dp[i][j][k];
    if(k)
        return dp[i][j][k]=solve(i+1,s,j,k)+solve(i+1,s,j^b[i][o],k);
    else
    {
        if(s[i]=='1')
            return ret=solve(i+1,s,j,1)+solve(i+1,s,j^b[i][o],k);
        else
            return ret=solve(i+1,s,j,k);
    }
}
main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>o;
    for(int i=1;i<=m;i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        v[i].push_back(t1);
        v[i].push_back(t2);
    }
    for(int i=0;i<110;i++)
        for(int j=0;j<maxn;j++)
            b[i][j]=-1;
    for(int i=1;i<=n;i++)
        dfs(i,o);
    string a,q,t1,t2;
    cin>>t1>>t2;
    a+='0';
    q+='0';
    a+=t1;
    q+=t2;
    int ans=0;
    bool c=0;
    for(int i=1;i<=n;i++)
        if(a[i]=='1'&&b[i][o])
            c=1-c;
    ans+=c;
    for(int i=0;i<1010;i++)
        for(int j=0;j<=1;j++)
            for(int k=0;k<=1;k++)
                dp[i][j][k]=-1;
    ans+=solve(1,q,0,0);
    for(int i=0;i<1010;i++)
        for(int j=0;j<=1;j++)
            for(int k=0;k<=1;k++)
                dp[i][j][k]=-1;
    ans-=solve(1,a,0,0);
    cout<<ans<<endl;
    return 0;
}
