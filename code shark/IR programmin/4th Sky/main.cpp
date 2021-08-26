#include <bits/stdc++.h>
//#define int long long int
using namespace std;
const int maxn=5e6;
int mod=12893;
int dp[1000][50];
int a[1000];
int cnt=0;
bool p[13000];
int solve(int x,int y)
{
    //cerr<<"X&Y : "<<x<<" "<<y<<endl;
    //getchar();
    if(y==0)
        return 0;
    int &ret=dp[x][y];
    if(ret!=-1)
        return ret;
    ret=0;
    for(int i=1;a[i]<=x;i++)
    {
        if(x==a[i])
        {
            //cerr<<"FUCK"<<endl;
            ret=a[i];
            return ret;
        }
        ret=solve(x-a[i],y-1);
        if(ret)
            return ret=a[i];
    }
    return ret;
}
main()
{
    for(int i=2;i<=mod;i++)
        if(!p[i])
            for(int j=i*i;j<=mod;j+=i)
                p[j]=1;
    for(int i=1;i<(1<<7);i++)
    {
        bool b=0;
        int t1=0,t2=0;
        for(int j=0;j<7;j++)
        {
            if(i&(1<<j))
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
        a[cnt+1]=t1;
        a[cnt+2]=t2;
        cnt+=2;
    }
    sort(a+1,a+1+cnt);
    ///for(int i=1;i<=cnt;i++)
       /// cerr<<a[i]<<" ";
    int l,r;
    cin>>l>>r;
    int g=mod;
    for(int i=0;i<=r;i++)
        for(int j=0;j<95;j++)
            dp[i][j]=-1;
    int ans=0;
    for(int i=l;i<=r;i++)
    {
        int t=1;
        while(solve(i,t)==0)
        {
            t++;
            //cerr<<t<<endl;
            //getchar();
        }
        int x=1,m=i;
        //cerr<<"T : "<<t<<endl;
        while(m)
        {
            //cerr<<m<<" "<<t<<endl;
            //getchar();
            //cerr<<dp[m][t]<<" ";
            x=(x*dp[m][t])%mod;
            g=min(g,dp[m][t]);
            m-=dp[m][t];
            t--;
        }//cerr<<endl;
        ans=(ans+x)%mod;
    }
    //cerr<<g<<endl;
    /*for(int i=mod-1;i>1;i--)
    {
        if(!p[i])
            g--;
        if(g==0)
        {
            mod=i;
            break;
        }
    }*/
    //cerr<<mod<<endl;
    int ret=1;
    for(int i=1;i<=1394;i++)
        ret=(ret*ans)%mod;
    cout<<ret;
    return 0;
}
