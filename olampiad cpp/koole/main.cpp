revale #include <iostream>

using namespace std;

int dp[10000][10000];

pair<int,int> a[10000] ;
int main()
{
    int n , v ;
    cin >> n >> v ;
    for (int i=0 ; i<n ; i++)
    {
        cin>>a[i].first;
        cin>>a[i].second;
    }

    for ( int i=0 ; i<=n ; i++)
    {
        for ( int j=0 ; j<=v ; j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else
            {
                if(a[i].second>j)
                    dp[i][j]=dp[i-1][j];
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i].second]+a[i].first);
                }
            }
        }
    }
    cout<<dp[n][v];
    return 0;
}
