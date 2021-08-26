///DARK PROGRAMMER



#include <bits/stdc++.h>

using namespace std;
const int maxn=100;
bool b[maxn][maxn][maxn][maxn];
int n,m;
string o,a;
void dfs(int x,int y,int i,int j)
{
    b[x][y][i][j]=1;
    if(o[x]=='>'&&y<m-1&&!b[x][y+1][i][j])
    {
        dfs(x,y+1,i,j);
    }
    if(o[x]=='<'&&y>0&&!b[x][y-1][i][j])
    {
        dfs(x,y-1,i,j);
    }
    if(a[y]=='^'&&x>0&&!b[x-1][y][i][j])
    {
        dfs(x-1,y,i,j);
    }
    if(a[y]=='v'&&x<n-1&&!b[x+1][y][i][j])
    {
        dfs(x+1,y,i,j);
    }
}
int main()
{
    cin>>n>>m;
    cin>>o>>a;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            dfs(i,j,i,j);
    for(int q=0;q<n;q++)
    {
        for(int w=0;w<m;w++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(!b[i][j][q][w])
                    {
                        cout<<"NO";
                        return 0;
                    }
                }
            }
        }
    }

    cout<<"YES";
    return 0;
}
