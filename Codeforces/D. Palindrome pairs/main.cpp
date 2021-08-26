#include <iostream>
#include <string>

using namespace std;
long long int dp[2000+10][2000+10],p[2000+10],s[2000+10];
long long int n,ans;
string str;
int main()
{
    cin>>str;
    n=str.size();
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i;j<n;j++)
        {
            if(i==j)
                dp[i][j]++;
            else if(i==j-1)
            {
                if(str[i]==str[j])
                    dp[i][j]++;
            }
            else
            {
                if(str[i]==str[j])
                if(dp[i+1][j-1]==1)
                    dp[i][j]++;
            }
        }
    }
    p[-1]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
            p[i]+=dp[i][j];
    }
    for(int i=0;i<n;i++)
    {
        s[i]=s[i-1]+p[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
            {
                if(dp[i][j]==1)
                {
                    ans+=s[n-1]-s[j];
                }
            }
    }
    cout<<ans;
    return 0;
}
