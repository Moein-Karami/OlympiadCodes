///Chefer


#include <bits/stdc++.h>
#define int long long int
using namespace std;
int dp[11][1<<12][101];
int n,k;
vector <int> v[1<<12];
int biti[1<<12];
int solve(int x,int mask,int t)
{
    //cerr<<mask<<endl;
    if(t>k)
        return 0;
    if(x>n)
        return (t==k);
    if(dp[x][mask][t]!=-1)
        return dp[x][mask][t];
    dp[x][mask][t]=0;
    for(int i=0;i<v[mask].size();i++)
        dp[x][mask][t]+=solve(x+1,v[mask][i],t+biti[v[mask][i]]);
    return dp[x][mask][t];
}
main()
{
    cin>>n>>k;

    for(int i=0;i<(1<<12);i++)
        for(int j=0;j<11;j++)
            for(int k=0;k<101;k++)
                dp[j][i][k]=-1;
    for(int mask=0;mask<(1<<n);mask++)
    {
        for(int i=0;i<(1<<n);i++)
        {

            int bit=0;
            bool b=1;
            for(int j=0;j<10;j++)
            {
                if(j>0&&(i&(1<<j))&&(i&(1<<(j-1))))
                {
                    b=0;
                    break;
                }
                if(i&(1<<j))
                {
                    bit++;
                    if(((1<<max(0LL,j-1))&mask)!=0||(((1<<j)&mask)!=0)||(((1<<min(n,j+1))&mask)!=0))
                        b=0;//,cerr<<"FUCK"<<endl;
                }
            }
            if(b)
                v[mask].push_back(i),biti[i]=bit;
        }
    }
    int ans=solve(1,0,0);
    cout<<ans;
    return 0;
}
