#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod=1e9+7,mod1=10567;
int dp[260][260][260];
int p(int x,int y)
{
    int ret=1;
    while(y)
    {
        if(y%2)
            ret=(ret*x)%mod;
        x=(x*x)%mod;
        y/=2;
    }
    return ret;
}
int solve(int x,int y,int k)
{
    k%=257;
    //cerr<<"X&Y : "<<x<<" "<<y<<endl;
    if(x==257)
        x=1;
    if(y==0)
        y=256;
    int &ret=dp[x][y][k];
    if(ret!=-1)
        return ret;
    if(x==y)
        return (x*k)%257;
    ret=solve(x+1,y,k*k*x);
    ret=(ret+solve(x,y-1,k*k*y))%mod;
    //cerr<<"X&Y&K : "<<x<<" "<<y<<" "<<k<<" "<<ret<<endl;
    //getchar();
    return ret;
}
main()
{
    for(int i=0;i<260;i++)
        for(int j=0;j<260;j++)
            for(int k=0;k<260;k++)
                dp[i][j][k]=-1;
    int l,r,t=1;
    l=1,r=256;
    int ans=0;
    int n=1000000000-1000000000/257;
    int x1=1,x2=256;
    //cerr<<n<<endl;
    while(x2<=n)
    {
        //cerr<<l<<" "<<r<<" "<<x<<endl;
        //getchar();
        ans=(ans+solve(l,r,1)*t)%mod;
        //cerr<<"SHIT"<<endl;
        //cerr<<x2<<" "<<n-x2<<" "<<x1<<" "<<t<<endl;
        //getchar();
        t=(((t*(n-x2))%mod)*p(x1,mod-2))%mod;
        l++;
        r++;
        x1++;
        x2++;
        if(r%257==0)
            r=1;
        if(l%257==0)
            l=1;
        //if(x2>=n-10)
            //cerr<<ans<<" "<<x2<<" "<<t<<"\n";;
        if(x2%100000000==0)
            cerr<<x2<<endl;
    }
    //cout<<ans<<endl;
    cout<<ans%mod1;
    return 0;
}
