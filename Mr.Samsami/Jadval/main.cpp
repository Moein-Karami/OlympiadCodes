#include <iostream>

using namespace std;
bool b[4+10][6+10];
int jadval[4+10][6+10];
int ans;
void clean()
{
    for(int i=0;i<=3;i++)
    {
        for(int j=0;j<=5;j++)
        {
            jadval[i][j]=0;
            b[i][j]=0;
        }
    }
}
void solve(int x,int y)
{
    if(x==3&&y==5)
    {
        return ;
    }
    for(int i=-1;i<=1;i++)
    {
        for(int j=-1;j<=1;j++)
        {
            if(j!=i&&j!=-i)
            {
                if(jadval[x+i][y+j]==1&&b[x+i][j+y]==0)
                {
                    b[x+i][j+y]=1;
                    solve(x+i,j+y);
                }
            }
        }
    }
}
int main()
{
    for(int i=0;i<(1<<24);i++)
    {
        clean();
        for(int j=0;j<24;j++)
        {
            if(i&(1<<(j)))
            {
                jadval[j%4][j/4]=1;
            }
        }
        if(jadval[0][0])
        {
            b[0][0]=1;
            solve(0,0);
            if(b[3][5])
            {

                ans++;
            }
        }

    }
    cout<<ans;
    return 0;
}
