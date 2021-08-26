///DARK PROGRAMMER

#include <iostream>

using namespace std;
bool dp[1010][1010];
int a[1010];
int ans[1010];
int main()
{
    int n,k;
    int t;
    cin>>t;
    for(int q=1;q<=t;q++)
    {
        ///
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<=n;j++)
            {
               dp[i][j]=0;
            }
        }
        ///
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<=n;j++)
            {
               if(dp[i][j-1]||i==a[j])
                    dp[i][j]=1;
                if(i>a[j]&&j>=2)
                    if(dp[i-a[j]][j-2])
                        dp[i][j]=1;
            }
        }

        int x=0;
        for(int i=k;i>=1;i--)
        {
            if(dp[i][n])
            {
                ans[q]=i;
                i=0;
            }
        }
    }
    for(int i=1;i<=t;i++)
        cout<<"Scenario #"<<i<<": "<<ans[i]<<endl;
    return 0;
}
