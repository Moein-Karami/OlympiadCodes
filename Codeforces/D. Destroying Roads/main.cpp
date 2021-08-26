///Chefer



#include <bits/stdc++.h>

using namespace std;
const int maxn=3e3+3;
vector <int> v[maxn];
int h[maxn][maxn];
bool b[maxn][maxn];
main()
{
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        v[t1].push_back(t2);
        v[t2].push_back(t1);
    }
    queue <int> q;
    int x;
    int u;
    for(int i=1;i<=n;i++)
    {
        q.push(i);
        b[i][i]=1;
        while(q.size())
        {
            x=q.front();
            q.pop();
            for(int j=0;j<v[x].size();j++)
            {
                u=v[x][j];
                if(!b[i][u])
                {
                    b[i][u]=1;
                    q.push(u);
                    h[i][u]=h[i][x]+1;
                }
            }
        }
    }
    int s1,t1,l1,s2,t2,l2;
    cin>>s1>>t1>>l1>>s2>>t2>>l2;
    if(h[s1][t1]>l1||h[s2][t2]>l2)
    {
        cout<<-1;
        return 0;
    }
    int ans=h[s1][t1]+h[s2][t2];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(h[t1][i]+h[i][j]+h[j][s1]<=l1&&h[t2][i]+h[i][j]+h[j][s2]<=l2)
                ans=min(ans,h[t1][i]+h[t2][i]+h[i][j]+h[s1][j]+h[s2][j]);
            if(h[t1][i]+h[i][j]+h[j][s1]<=l1&&h[t2][j]+h[i][j]+h[i][s2]<=l2)
                ans=min(ans,h[t1][i]+h[t2][j]+h[i][j]+h[s1][j]+h[s2][i]);
        }
    }
    cout<<m-ans;
    return 0;
}
