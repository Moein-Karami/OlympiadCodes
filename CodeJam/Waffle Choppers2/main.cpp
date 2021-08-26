#include <bits/stdc++.h>

using namespace std;
const int maxn=110;
int a[maxn][maxn];
int tmp[maxn];
int n,m,h,v,s;
bool solve(int x,int y)
{
    int t1=0,t2=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==1)
            {
                if(j<=y)
                    t1++;
                else
                    t2++;
            }
        }
        if(i==x||i==n)
        {
            if(t1!=s||t2!=s)
                return 0;
            t1=0;
            t2=0;
        }
    }
    return 1;
}
main()
{
    int T;
    cin>>T;
    for(int Q=1;Q<=T;Q++)
    {
        for(int i=0;i<maxn;i++)
        {
            for(int j=0;j<maxn;j++)
                a[i][j]=0;
            tmp[i]=0;
        }
        int n,m,h,v;
        cin>>n>>m>>h>>v;
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                char c;
                cin>>c;
                if(c=='@')
                    cnt++,a[i][j]=1;
            }
        }
        if(cnt==0)
        {
            cout<<"Case #"<<Q<<": POSSIBLE\n";
            continue;
        }
        if(cnt%((h+1)*(v+1))!=0)
        {
            cout<<"Case #"<<Q<<": IMPOSSIBLE\n";
            continue;
        }
        else s=cnt/((h+1)*(v+1));
        bool b=0;
        for(int i=1;i<n;i++)
            for(int j=1;j<m;j++)
                if(solve(i,j))
                    b=1;
        if(b)
            cout<<"Case #"<<Q<<": POSSIBLE\n";
        else
            cout<<"Case #"<<Q<<": IMPOSSIBLE\n";
    }
    return 0;
}
