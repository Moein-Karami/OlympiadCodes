///DARK PROGRAMER



#include <bits/stdc++.h>

using namespace std;
char a[100][100];
bool b[100][100];
int n,m;
void bfs(int p1,int p2,int i, int j)
{
    for(int q=-1;q<=1;q++)
    {
        for(int w=-1;w<=1;w++)
        {
            if(w!=q&&w!=-q)
            {
                if(i+q!=p1||j+w!=p2)
                {
                    if(b[i+q][j+w]&&a[i+q][j+w]==a[i][j])
                    {
                        cout<<"Yes";
                        exit(0);
                    }

                    if(!b[i+q][j+w]&&a[i+q][j+w]==a[i][j])
                    {
                        b[i+q][j+w]=1;
                        bfs(i,j,i+q,j+w);
                    }
                }

            }
        }
    }

}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int q=1;q<=n;q++)
                for(int w=1;w<=m;w++)
                    b[q][w]=0;

            b[i][j]=1;
            bfs(i,j,i,j);
        }
    }
    cout<<"No";
    return 0;
}
