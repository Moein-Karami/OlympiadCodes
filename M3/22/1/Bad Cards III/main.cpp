#include <bits/stdc++.h>
#define int long long int
using namespace std;
string s[20];
int dp[1<<18];
const int inf=1e17,mod=10009;
string ex;
int solve(int x,int y)
{
    if(x==0)
        return 0;
    if(dp[x]!=-1)
        return dp[x];
    dp[x]=inf;
    for(int i=0;i<16;i++)
        if((1<<i)&x)
            dp[x]=min(dp[x],(i+1)*(1LL<<(y-s[i].size()))+solve(x-(1<<i),y-s[i].size()));
    return dp[x];
}
int make (int x,int y)
{
    if(dp[x]!=-1)
        return dp[x];
    if(x==0)
        return dp[x]=1;
    dp[x]=0;
    for(int i=0;i<16;i++)
    {
        if(x&(1<<i))
        {
            bool b=1;
            for(int j=0;j<s[i].size();j++)
            {
                if(s[i][j]!=ex[y+j])
                {
                    b=0;
                    break;
                }
            }
            if(b)
                dp[x]=(dp[x]+make(x-(1<<i),y+s[i].size()))%mod;
        }
    }
    cerr<<x<<" "<<dp[x]<<endl;
    return dp[x];
}
main()
{
    for(int i=0;i<(1<<18);i++)
        dp[i]=-1;
    for(int i=0;i<16;i++)
    {
        int t=i+1;
        while(t)
        {
            if(t%2)
                s[i]+='1';
            else
                s[i]+='0';
            t/=2;
        }
        reverse(s[i].begin(),s[i].end());
    }
    int x=solve((1<<16)-1,54);
    int t=x;
    while(t)
    {
        if(t%2)
            ex+='1';
        else
            ex+='0';
            t/=2;
    }
    reverse(ex.begin(),ex.end());
    for(int i=0;i<(1<<18);i++)
        dp[i]=-1;
    cerr<<ex<<endl;
    x%=mod;
    t=make((1<<16)-1,0);
    cerr<<t<<endl;
    t%=mod;
    cout<<(x*t)%mod;

    return 0;
}
