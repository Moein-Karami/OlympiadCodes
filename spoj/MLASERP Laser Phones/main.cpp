///DARK PROGRAMMER



#include <bits/stdc++.h>

#define f first
#define s second
#define tf tmp.first
#define ts tmp.second

using namespace std;

const int maxn=111;

typedef pair<int,int> pii;
bool b[maxn][maxn];
queue <pii> q;
int ans[maxn][maxn][4];
pii parent[maxn][maxn];
char a[maxn][maxn];

int main()
{
    for(int i=0;i<maxn;i++)
        for(int j=0;j<maxn;j++)
            for(int q=0;q<4;q++)
                ans[i][j][q]=1e9;
    int n,m;
    cin>>n>>m;

    pii cow1,cow2;
    bool c=1;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            if(a[i][j]=='*')
                b[i][j]=1;
            if(!c&&a[i][j]=='C')
            {
                cow2.f=i;
                cow2.s=j;
            }
            if(c&&a[i][j]=='C')
            {
                parent[i][j].f=i;
                parent[i][j].s=j;
                cow1.f=i;
                cow1.s=j;
                q.push(pii(i,j));
                c=0;
                b[i][j]=1;
                for(int w=0;w<4;w++)
                    ans[i][j][w]=0;
            }
        }
    }
    while(q.size())
    {
        pii tmp=q.front();
        c=0;
        ///payin
        if(tf+1!=parent[tf][ts].f)
        {
            if(a[tf+1][ts]=='.'||a[tf+1][ts]=='C')
            {
                if(!b[tf+1][ts])
                {
                    b[tf+1][ts]=1;
                    ans[tf+1][ts][1]=min(ans[tf][ts][1],min(ans[tf][ts][0],ans[tf][ts][2])+1);
                    parent[tf+1][ts].f=tf;
                    parent[tf+1][ts].s=ts;
                    c=1;
                }
                else
                {
                    if(ans[tf+1][ts][1]>ans[tf][ts][1])
                    {
                        ans[tf+1][ts][1]=ans[tf][ts][1];
                        parent[tf+1][ts].f=tf;
                        parent[tf+1][ts].s=ts;
                        c=1;
                    }
                    if(ans[tf+1][ts][1]>ans[tf][ts][0]+1)
                    {
                        ans[tf+1][ts][1]=ans[tf][ts][0]+1;
                        parent[tf+1][ts].f=tf;
                        parent[tf+1][ts].s=ts;
                        c=1;
                    }
                    if(ans[tf+1][ts][1]>ans[tf][ts][2]+1)
                    {
                        ans[tf+1][ts][1]=ans[tf][ts][2]+1;
                        parent[tf+1][ts].f=tf;
                        parent[tf+1][ts].s=ts;
                        c=1;
                    }
                }
                if(c)
                {
                    q.push(pii(tf+1,ts));
                }
            }

        }
        c=0;
        ///rast
        if(ts+1!=parent[tf][ts].s)
        {
            if(a[tf][ts+1]=='.'||a[tf][ts+1]=='C')
            {
                if(!b[tf][ts+1])
                {
                    b[tf][ts+1]=1;
                    ans[tf][ts+1][0]=min(ans[tf][ts][0],min(ans[tf][ts][1],ans[tf][ts][3])+1);
                    parent[tf][ts+1].f=tf;
                    parent[tf][ts+1].s=ts;
                    c=1;
                }
                else
                {
                    if(ans[tf][ts+1][0]>ans[tf][ts][0])
                    {
                        ans[tf][ts+1][0]=ans[tf][ts][0];
                        parent[tf][ts+1].f=tf;
                        parent[tf][ts+1].s=ts;
                        c=1;
                    }
                    if(ans[tf][ts+1][0]>ans[tf][ts][1]+1)
                    {
                        ans[tf][ts+1][0]=ans[tf][ts][1]+1;
                        parent[tf][ts+1].f=tf;
                        parent[tf][ts+1].s=ts;
                        c=1;
                    }
                    if(ans[tf][ts+1][0]>ans[tf][ts][3]+1)
                    {
                        ans[tf][ts+1][0]=ans[tf][ts][3]+1;
                        parent[tf][ts+1].f=tf;
                        parent[tf][ts+1].s=ts;
                        c=1;
                    }
                }
                if(c)
                {
                    q.push(pii(tf,ts+1));
                }
            }

        }
        c=0;
        ///bala
        if(tf-1!=parent[tf][ts].f)
        {
            if(a[tf-1][ts]=='.'||a[tf-1][ts]=='C')
            {
                if(!b[tf-1][ts])
                {
                    b[tf-1][ts]=1;
                    ans[tf-1][ts][3]=min(ans[tf][ts][3],min(ans[tf][ts][0],ans[tf][ts][2])+1);
                    parent[tf-1][ts].f=tf;
                    parent[tf-1][ts].s=ts;
                    c=1;
                }
                else
                {
                    if(ans[tf-1][ts][3]>ans[tf][ts][3])
                    {
                        ans[tf-1][ts][3]=ans[tf][ts][3];
                        parent[tf-1][ts].f=tf;
                        parent[tf-1][ts].s=ts;
                        c=1;
                    }
                    if(ans[tf-1][ts][3]>ans[tf][ts][0]+1)
                    {
                        ans[tf-1][ts][3]=ans[tf][ts][0]+1;
                        parent[tf-1][ts].f=tf;
                        parent[tf-1][ts].s=ts;
                        c=1;
                    }
                    if(ans[tf-1][ts][3]>ans[tf][ts][2]+1)
                    {
                        ans[tf-1][ts][3]=ans[tf][ts][2]+1;
                        parent[tf-1][ts].f=tf;
                        parent[tf-1][ts].s=ts;
                        c=1;
                    }
                }
                if(c)
                {
                    q.push(pii(tf-1,ts));
                }
            }

        }
        c=0;
        ///Chap
        if(ts-1!=parent[tf][ts].s)
        {
            if(a[tf][ts-1]=='.'||a[tf][ts-1]=='C')
            {
                if(!b[tf][ts-1])
                {
                    b[tf][ts-1]=1;
                    ans[tf][ts-1][2]=min(ans[tf][ts][2],min(ans[tf][ts][1],ans[tf][ts][3])+1);
                    parent[tf][ts-1].f=tf;
                    parent[tf][ts-1].s=ts;
                    c=1;
                }
                else
                {
                    if(ans[tf][ts-1][2]>ans[tf][ts][2])
                    {
                        ans[tf][ts-1][2]=ans[tf][ts][2];
                        parent[tf][ts-1].f=tf;
                        parent[tf][ts-1].s=ts;
                        c=1;
                    }
                    if(ans[tf][ts-1][2]>ans[tf][ts][1]+1)
                    {
                        ans[tf][ts-1][2]=ans[tf][ts][1]+1;
                        parent[tf][ts-1].f=tf;
                        parent[tf][ts-1].s=ts;
                        c=1;
                    }
                    if(ans[tf][ts-1][2]>ans[tf][ts][3]+1)
                    {
                        ans[tf][ts-1][2]=ans[tf][ts][3]+1;
                        parent[tf][ts-1].f=tf;
                        parent[tf][ts-1].s=ts;
                        c=1;
                    }
                }
                if(c)
                {
                    q.push(pii(tf,ts-1));
                }
            }
        }
        q.pop();
    }
    int answer=1e9;
    for(int i=0;i<4;i++)
    {
        answer=min(answer,ans[cow2.f][cow2.s][i]);
    }
    cout<<answer;
    return 0;
}
