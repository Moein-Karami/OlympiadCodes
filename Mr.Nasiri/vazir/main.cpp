///DARK PROGRAMMER


#include <iostream>

using namespace std;
int n;
bool a[100],ghr[100],ghch[100];
int dp[100][100];
void solve(int x)
{
    if(x==n+1)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!a[i]&&!ghr[i-x]&&!ghch[i+x])
        {
            a[i]=1;
            ghr[i-x]=1;
            ghch[i+x]=1;
            dp[x][i]=1;
            solve(x+1);
            dp[x][i]=0;
            a[i]=0;
            ghr[i-x]=0;
            ghch[i+x]=0;
        }
    }
    return ;
}
int main()
{

    cin>>n;
    solve(1);
    return 0;
}
