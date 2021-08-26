#include <iostream>

using namespace std;
long long int dp[101][101][11][2];
const long long int mod=1e8;
int main()
{
    int n1,n2,k1,k2,n;
    cin>>n1>>n2>>k1>>k2;
    n=n1+n2;
    dp[0][1][0][1]=1;
    dp[1][0][0][0]=1;
    for(int i=0;i<=n1;i++)
    {
        for(int j=0;j<=n2;j++)
        {
            for(int q=0;q<max(k1,k2);q++)
            {
                for(int z=0;z<=1;z++)
                {

                    if(q>=k1&&z==0)
                        dp[i][j][q][z]=0;
                    else if(q>=k2&&z==1)
                        dp[i][j][q][z]=0;
                    else if(q>=n1&&z==0)
                        dp[i][j][q][z]=0;
                    else if(q>=n2&&z==1)
                        dp[i][j][q][z]=0;
                    else if(q==0&&z==1)
                    {
                        for(int f=0;f<k1;f++)
                        {
                            if(f<i)
                                dp[i][j][q][z]+=(dp[i][j-1][f][0])%mod;
                        }
                    }
                    else if(q==0&&z==0)
                    {
                        for(int f=0;f<k2;f++)
                        {
                            if(f<j)
                                dp[i][j][q][z]+=(dp[i-1][j][f][1])%mod;
                        }
                    }
                    else if(q!=0&&z==0)
                        dp[i][j][q][z]+=(dp[i-1][j][q-1][0])%mod;
                    else if(q!=0&&z==1)
                        dp[i][j][q][z]+=(dp[i][j-1][q-1][1])%mod;
                }
            }
        }
    }
    long long int ans=0;
    for(int i=0;i<k1;i++)
    {
        ans=(ans+dp[n1][n2][i][0])%mod;
    }
    for(int i=0;i<k2;i++)
    {
        ans=(ans+dp[n1][n2][i][1])%mod;
    }
    cout<<ans%mod;
    return 0;
}
