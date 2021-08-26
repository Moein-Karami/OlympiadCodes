///Chefer


#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
map<pii,int> pti;
map<int,pii> itp;
bool b[12][23][23];
int h[12][23][23];
int n,m;
char c[23][23];
int cnt;
pii o;
int dp[13][1<<12];
const int inf=1e9;
int solve(int x,int mask)
{
    if(mask==0)
        return 0;
    if(dp[x][mask])
        return dp[x][mask];
    int &ret=dp[x][mask];
    ret=inf;
    for(int i=0;i<cnt;i++)
    {
        if((1<<i)&mask)
        {
            ret=min(ret,h[x][itp[i].f][itp[i].s]+solve(i,mask-(1<<i)));
        }
    }
    return ret;
}
void clean()
{
    cnt=0;
    o.f=0;
    o.s=0;
    for(int i=0;i<12;i++)
        for(int j=0;j<(1<<12);j++)
            dp[i][j]=0;
    for(int i=0;i<12;i++)
    {
        for(int j=0;j<23;j++)
        {
            for(int k=0;k<23;k++)
            {
                b[i][j][k]=0;
                h[i][j][k]=0;
                if(j==0||k==0||j==n+1||k==m+1)
                    c[j][k]='x';
            }
        }
    }
}
main()
{
    while(1)
    {
        cin>>m>>n;
        if(n==0&&m==0)
            return 0;
        clean();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>c[i][j];
                if(c[i][j]=='*')
                {
                    pti[pii(i,j)]=cnt;
                    itp[cnt]=pii(i,j);
                    cnt++;
                }
                else if(c[i][j]=='o')
                    o.f=i,o.s=j;
            }
        }
        pti[o]=cnt;
        itp[cnt]=o;
        queue<pii> q;
        pii t;

        for(int i=0;i<=cnt;i++)
        {
            q.push(itp[i]);
            b[i][itp[i].f][itp[i].s]=1;

            while(q.size())
            {
                t=q.front();
                //cout<<t.f<<" "<<t.s<<endl;
                q.pop();
                for(int j=-1;j<=1;j++)
                {
                    for(int k=-1;k<=1;k++)
                    {
                        if(k!=j&&k!=-j)
                        {
                            if(!b[i][t.f+j][t.s+k]&&c[t.f+j][t.s+k]!='x')
                            {
                                b[i][t.f+j][t.s+k]=1;
                                h[i][t.f+j][t.s+k]=h[i][t.f][t.s]+1;
                                q.push(pii(t.f+j,t.s+k));
                            }
                        }
                    }
                }
            }
        }
        bool check=1;
        for(int i=0;i<cnt;i++)
        {
            if(!b[cnt][itp[i].f][itp[i].s])
                check=0;
        }
        if(!check)
        {
            cout<<-1<<endl;
            continue;
        }
        cout<<solve(cnt,(1<<cnt)-1)<<endl;
    }
}
