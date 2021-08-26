#include <iostream>

using namespace std;
int dp[10000][10000];

int main()
{
    int x , y ;
    cin >>x>>y ;

    for ( int i=0 ; i<=x ; i++)
    {
        for (int j=0 ; j<=i ; j++)
        {
            if(j==0 || i==j)
            dp[i][j]=1;
            else
            dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
        }
    }
    cout <<dp[x][y];
    return 0;
}
