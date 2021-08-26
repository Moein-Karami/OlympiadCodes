#include <iostream>

using namespace std;
const int maxn =100;
int n;
int dp[maxn][maxn];
bool b[maxn];
void solve(int x)
{
    if(x==n+1)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                cout<<dp[i][j];
            cout<<endl;
        }
         cout<<"_______________"<<endl;
         return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(b[i])
            continue ;
        dp[x][i]=1;
        b[i]=1;
        solve(x+1);
        b[i]=0;
        dp[x][i]=0;
    }
}

int main()
{
    cin>>n;
    solve(1);
    return 0;
}
