///DARK PROGRAMMER


#include <iostream>

using namespace std;
int n,m,ans;
char a[8][8];
bool b[8][8];
int chefer(int i,int j)
{
    b[i][j]=1;
    if(i==0&&j==m-1)
    {
        bool c=1;
        for(int q=0;q<n;q++)
        {
            for(int w=0;w<m;w++)
            {
                if(b[q][w]==0)
                {
                    c=0;
                }

            }

        }
        b[i][j]=0;
        return c;
    }
    int ans=0;
    if(i+1<n&&!b[i+1][j])
        ans+=chefer(i+1,j);
    if(i-1>=0&&!b[i-1][j])
        ans+=chefer(i-1,j);
    if(j+1<m&&!b[i][j+1])
        ans+=chefer(i,j+1);
    if(j-1>=0&&!b[i][j-1])
        ans+=chefer(i,j-1);
     b[i][j]=0;
     return ans;
}
int main()
{
    n=1;
    m=1;
    while(n&&m)
    {
        cin>>n>>m;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<m;j++)
            {
                b[i][j]=0;
                cin>>a[i][j];
                if(a[i][j]=='#')
                    b[i][j]=1;
            }
        }
        cout<<chefer(0,0)<<endl;
    }
    return 0;
}
