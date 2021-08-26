#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod=12917;
const int maxn=1e3;
int dp[maxn][maxn];
vector<int> v;
int solve(int x,int y)
{
    if(dp[x][y]!=-1)
        return dp[x][y];
    dp[x][y]=0;
    if(y==0)
        return 0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]>x)
            break;
        if(v[i]==x)
            return v[i];
        if(solve(x-v[i],y-1))
        return dp[x][y]=v[i];
    }
    return 0;
}
main()
{
    for(int i=1;i<(1<<3);i++)
    {
        bool b=0;
        int t1=0,t2=0;
        for(int j=0;j<3;j++)
        {
            if((1<<j)&i)
            {
                b=1;
                t1=t1*10+4;
                t2=t2*10+7;
            }
            else if(b)
            {
                t1=t1*10+7;
                t2=t2*10+4;
            }
        }
        v.push_back(t1);
        v.push_back(t2);
    }
    sort(v.begin(),v.end());
    for(int T=75;T<=100;T++)
    {
        int l=1,r=T;
        while(l+1!=r)
        {
            for(int i=0;i<=T;i++)
                for(int j=0;j<=t;j++)
                    dp[i][j]=-1;
            int mid=(l+r)/2;
            if(solve(T,mid))
                l=mid;
            else
                r=mid;
        }
        int x=T,y=l;
        while()
    }
    return 0;
}
