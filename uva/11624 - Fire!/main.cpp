#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii ;

#define s second

#define f first

const int maxn=1010;

char safe[maxn][maxn];

bool b[maxn][maxn];
bool b1[maxn][maxn];
int javab[maxn];
queue <pii> q[2];
int ans1[maxn][maxn];
int ans[maxn][maxn];
int main()
{
    int u;
    cin>>u;
    for(int l=1;l<=u;l++)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<=n+1;i++)
        {
            for(int j=0;j<=m+1;j++)
            {
                b[i][j]=0;
                b1[i][j]=0;
                safe[i][j]='.';
                ans1[i][j]=1e9;
                ans[i][j]=0;
            }
        }

        for(int i=0;i<=n+1;i++)
        {
            for(int j=0;j<=m+1;j++)
            {
                if(i==0||i==n+1||j==0||j==m+1)
                {
                    b1[i][j]=1;
                    b[i][j]=1;
                }
                else
                {
                    cin>>safe[i][j];
                    if(safe[i][j]=='F')
                    {
                        q[1].push(pii(i,j));
                        b1[i][j]=1;
                        ans1[i][j]=1;
                    }
                    if(safe[i][j]=='J')
                    {
                        q[0].push(pii(i,j));
                        b[i][j]=1;
                        ans[i][j]=1;
                    }
                    if(safe[i][j]=='#')
                    {
                        b[i][j]=1;
                        b1[i][j]=1;
                    }
                }

            }
        }
        while(q[0].size())
        {
            pii tmp=q[0].front();
            if(!b[tmp.f][tmp.s+1])
            {
                q[0].push(pii(tmp.f,tmp.s+1));
                b[tmp.f][tmp.s+1]=1;
                ans[tmp.f][tmp.s+1]=ans[tmp.f][tmp.s]+1;
            }

            if(!b[tmp.f+1][tmp.s])
            {
                q[0].push(pii(tmp.f+1,tmp.s));
                b[tmp.f+1][tmp.s]=1;
                ans[tmp.f+1][tmp.s]=ans[tmp.f][tmp.s]+1;
            }

            if(!b[tmp.f][tmp.s-1])
            {
                q[0].push(pii(tmp.f,tmp.s-1));
                b[tmp.f][tmp.s-1]=1;
                ans[tmp.f][tmp.s-1]=ans[tmp.f][tmp.s]+1;
            }

            if(!b[tmp.f-1][tmp.s])
            {
                q[0].push(pii(tmp.f-1,tmp.s));
                b[tmp.f-1][tmp.s]=1;
                ans[tmp.f-1][tmp.s]=ans[tmp.f][tmp.s]+1;
            }
            q[0].pop();
        }

    while(q[1].size())
        {
            pii tmp=q[1].front();
            if(!b1[tmp.f][tmp.s+1])
            {
                q[1].push(pii(tmp.f,tmp.s+1));
                b1[tmp.f][tmp.s+1]=1;
                ans1[tmp.f][tmp.s+1]=ans1[tmp.f][tmp.s]+1;
            }

            if(!b1[tmp.f+1][tmp.s])
            {
                q[1].push(pii(tmp.f+1,tmp.s));
                b1[tmp.f+1][tmp.s]=1;
                ans1[tmp.f+1][tmp.s]=ans1[tmp.f][tmp.s]+1;
            }

            if(!b1[tmp.f][tmp.s-1])
            {
                q[1].push(pii(tmp.f,tmp.s-1));
                b1[tmp.f][tmp.s-1]=1;
                ans1[tmp.f][tmp.s-1]=ans1[tmp.f][tmp.s]+1;
            }

            if(!b1[tmp.f-1][tmp.s])
            {
                q[1].push(pii(tmp.f-1,tmp.s));
                b1[tmp.f-1][tmp.s]=1;
                ans1[tmp.f-1][tmp.s]=ans1[tmp.f][tmp.s]+1;
            }
            q[1].pop();
        }
        javab[l]=1e9;
        for(int i=1;i<=n;i++)
        {
            if((ans[i][1]<ans1[i][1])&&(ans[i][1]<javab[l])&&(ans[i][1]!=0))
                javab[l]=ans[i][1];
        }

        for(int i=1;i<=n;i++)
            if(ans[i][m]<ans1[i][m]&&ans[i][m]<javab[l]&&ans[i][m]!=0)
                javab[l]=ans[i][m];
        for(int j=1;j<=m;j++)
            if(ans[1][j]<ans1[1][j]&&ans[1][j]<javab[l]&&ans[1][j]!=0)
                javab[l]=ans[1][j];
        for(int j=1;j<=m;j++)
            if(ans[n][j]<ans1[n][j]&&ans[n][j]<javab[l]&&ans[n][j]!=0)
                javab[l]=ans[n][j];
    }
    for(int i=1;i<=u;i++)
    {
        if(javab[i]==1e9)
            cout<<"IMPOSSIBLE";
        else
            cout<<javab[i];
        cout<<endl;
    }
    return 0;
}
