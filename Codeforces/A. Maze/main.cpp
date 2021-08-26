///DARK PROGRAMMER



#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int ,int > pii;
const int maxn=1e3;
char c[maxn][maxn];
int n,m,k,ans;
bool b[maxn][maxn];
int h[maxn][maxn];
vector <pair<int,int> > v[251000];
int maxi;
void dfs(int x,int y)
{
    for(int i=-1;i<=1;i++)
    {
        for(int j=-1;j<=1;j++)
        {
            if(!b[i+x][j+y]&&i!=j&&i!=-j&&c[i+x][j+y]=='.')
            {
                b[x+i][j+y]=1;
                h[i+x][j+y]=h[x][y]+1;
                v[h[x][y]+1].push_back(pii(i+x,j+y));
                if(maxi<h[x][y]+1)
                    maxi=h[x][y]+1;
                dfs(x+i,y+j);
            }
        }
    }
}
int main()
{
    int t1,t2;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>c[i][j];
            if(c[i][j]=='.')
            {
                ans++;
                t1=i;
                t2=j;
            }
        }
    }
    ans-=k;
    b[t1][t2]=1;
    v[0].push_back(pii(t1,t2));
    dfs(t1,t2);
    while(k)
    {
        for(int i=0;i<v[maxi].size();i++)
        {
            c[v[maxi][i].f][v[maxi][i].s]='X';
            k--;
            if(!k)
                break;
        }
        maxi--;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cout<<c[i][j];
        cout<<endl;
    }
    return 0;
}
