#include <bits/stdc++.h>
#define int long long int
using namespace std;
int a[] = {972, -1, 273, -1, 932, 911, -1, 233};
int b[] = { -1, 942, 135, -1, 371, -1, 311, -1};
const int k = 2,mod =10607;
int dp[1010][10];
main()
{
    ///1
    for(int i=100;i<1000;i++)
    {
        int c = 777;
        c = (c * 972 + 1) % i;
        dp[c][1]++;
    }
    ///
    ///2
    for(int i=0;i<1000;i++)
    {
        if(dp[i][1])
        {
            for(int j=100;j<1000;j++)
            {
                int c=i;
                c = (c * j + 2) % 942;
                dp[c][2]+=dp[i][2];
            }
        }
    }cout<<dp[777][2]<<endl;
    ///
    ///3
    for(int i=0;i<1000;i++)
    {
        if(dp[i][2])
        {
            int c=i;
            c = (c * 273 + 3) % 135;
            dp[c][3]+=dp[i][2];
        }
    }
    ///
    ///4
    for(int i=0;i<1000;i++)
    {
        if(dp[i][3])
        {
            for(int j=100;j<1000;j++)
            {
                for(int k=100;k<1000;k++)
                {
                    int c=i;
                    c = (c * j + 4) % k;
                    dp[c][4]++;
                }
            }
        }
    }
    ///
    ///5
    for(int i=0;i<1000;i++)
    {
        if(dp[i][4])
        {
            int c=i;
            c = (c * 932 + 3) % 371;
            dp[c][5]+=dp[i][4];
        }
    }
    ///
    ///6_8
    for(int i=6;i<=8;i++)
    {
        if(a[i-1]<0)
        {
            for(int j=0;j<1000;j++)
            {
                if(dp[j][i-1])
                {
                    for(int k=100;k<1000;k++)
                    {
                        {
                            int c=j;
                            c = (c * k + i) % b[i-1];
                            dp[c][i]+=dp[j][i-1];
                        }
                    }
                }
            }
        }
        else
        {
            for(int j=1;j<1000;j++)
            {
                if(dp[j][i-1])
                {
                    for(int k=100;k<1000;k++)
                    {
                        {
                            int c=j;
                            c = (c * a[i-1] + i) % k;
                            dp[c][i]+=dp[j][i-1];
                        }
                    }
                }
            }
        }
    }
    ///
    cout<<dp[2][777];
    return 0;
}
