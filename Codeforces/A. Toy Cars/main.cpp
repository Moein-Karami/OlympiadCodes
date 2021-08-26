#include <iostream>

using namespace std;
int m[1001][1001];
bool b[1001];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>m[i][j];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(m[i][j]==1)
                b[i]=1;
            else if(m[i][j]==2)
                b[j]=1;
            else if(m[i][j]==3)
            {
                b[j]=1;
                b[i]=1;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(!b[i])
            ans++;
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)
        if(!b[i])
        cout<<i<<" ";
    return 0;
}
