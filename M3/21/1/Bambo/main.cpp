#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=10487;
bool b[mod+10];
int dp[mod+10][15];
vector<int> v;
vector <int> num[mod+10];
int cnt;
int solve(int x,int y)
{
    if(dp[x][y]!=-1)
        return dp[x][y];
    if(x==cnt)
        return 0;
    dp[x][y]=solve(x+1,y);
    if(num[x][0]==y)
        dp[x][y]=max(dp[x][y],solve(x+1,num[x].back())+num[x].size()-1);
    return dp[x][y];
}
main()
{
    for(int i=0;i<mod+10;i++)
        for(int j=0;j<15;j++)
            dp[i][j]=-1;
    b[1]=1;
    for(int i=2;i<mod;i++)
    {
        if(!b[i])
        {
            if(i>10)
            {
                v.push_back(i);
                int t=i;
                while(t)
                {
                    num[cnt].push_back(t%10);
                    t/=10;
                }
                reverse(num[cnt].begin(),num[cnt].end());
                cnt++;
            }
            for(int j=i*i;j<=mod;j+=i)
                b[j]=1;
        }
    }
    int ans=0;
    for(int i=0;i<v.size();i++)
        ans=max(ans,num[i].size()+solve(i+1,num[i].back()));
    cout<<ans<<" "<<(ans*ans*ans)%mod;
    return 0;
}
