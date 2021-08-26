///DARK PROGRAMMER


#include <iostream>

using namespace std;

const int maxn=17;
int n;
int dp[1<<maxn][maxn];
int t[1<<maxn][maxn];
int a[maxn];

int get(int i,int x)
{
   if(a[i]>a[x])
        return 2;
   else
    return 2*(a[i]-a[x])+2;
}
int solve(int mask,int x)
{
    if(dp[mask][x])
        return dp[mask][x];
    if(mask==(1<<x))
    {
        t[mask][x]=1;
        return 2*(1+a[x]);
    }
    for(int i=0;i<n;i++)
        if(i!=x)
            if((1<<i)&mask)
            {
                dp[mask][x]=max(dp[mask][x],solve(mask-(1<<x),i)+get(i,x));
            }
    for(int i=0;i<n;i++)
        if(i!=x)
            if((1<<i)&mask)
            {
                if(dp[mask][x]==solve(mask-(1<<x),i)+get(i,x))
                {
                    t[mask][x]+=t[mask-(1<<x)][i];
                }
            }
    return dp[mask][x];
}

int main()
{
    int mask;
    cin>>n;
    while(n)
    {
        ///
        for(int i=0;i<(1<<16);i++)
            for(int j=0;j<=16;j++)
            {
                dp[i][j]=0;
                t[i][j]=0;
            }

        for(int i=0;i<17;i++)
            a[i]=0;
        ///
        for(int i=0;i<n;i++)
            cin>>a[i];
        mask=(1<<n)-1;
        int ans=0,r=0;
        for(int i=0;i<n;i++)
            ans=max(ans,solve((1<<n)-1,i));
        for(int i=0;i<n;i++)
            if(ans==solve((1<<n)-1,i))
                r+=t[(1<<n)-1][i];
        cout<<ans<<" "<<r;
        cin>>n;
    }

    return 0;
}
