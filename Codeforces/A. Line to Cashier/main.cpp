#include <iostream>

using namespace std;
int dp[110][110];
int a[110],p[110];;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<a[i];j++)
        {
            cin>>dp[i][j];
            p[i]+=dp[i][j];
        }

    }
    int ans=1e9;
    for(int i=0;i<n;i++)
    {
        if((p[i]*5)+(15*a[i])<ans)
            ans=(p[i]*5)+(15*a[i]);
    }
    cout<<ans;
    return 0;
}
