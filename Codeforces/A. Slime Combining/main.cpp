///DARK PROGRAMMER

#include <iostream>
#include <vector>
using namespace std;
vector <int> dp[1010000];
int main()
{
    int n;
    cin>>n;
    dp[1].push_back(1);

    for(int i=2;i<=n;i++)
    {
        if(i%2==0)
        {
            int s=dp[i/2].size();
            for(int j=0;j<s;j++)
                dp[i].push_back(dp[i/2][j]+1);
        }
        else
        {
            int s=dp[i/2].size();
            for(int j=0;j<s;j++)
                dp[i].push_back(dp[i/2][j]+1);
            dp[i].push_back(1);
        }
    }
    int s=dp[n].size();
    for(int i=0;i<s;i++)
        cout<<dp[n][i]<<" ";
    return 0;
}
