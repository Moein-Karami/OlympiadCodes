#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
const int maxn=110,mod=10949,inf=1e10;
int a[maxn][maxn];
int t[maxn][maxn];
int f[maxn][maxn];
int po3[maxn],po7[maxn];
int n,m,k;
int day;
bool check()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(a[i][j])
                return 1;
    return 0;
}
bool check2()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(!a[i][j])
                return 1;
    return 0;
}
void build()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            f[i][j]=k+(po7[i]*po3[j])%m;
    while(check2())
    {
        day++;
        int c[maxn][maxn];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                c[i][j]=0;
                for(int q=-1;q<=1;q++)
                    for(int w=-1;w<=1;w++)
                        if(q!=w&&q!=-w)
                            c[i][j]+=(a[i+q][w+j]!=0);
            }
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                a[i][j]+=c[i][j];
    }
}
int check3()
{
    bool ret=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]>=f[i][j])
            {
                t[i][j]=day;
                ret=0;
                a[i][j]=0;
            }
            else if(a[i][j])
            {
                int s=0;
                for(int q=-1;q<=1;q++)
                    for(int w=-1;w<=1;w++)
                        if(w!=q&&w!=-q)
                            if(a[i+q][j+w])
                                s++;
                if(!s)
                {
                    t[i][j]=0;
                    a[i][j]=0;
                    ret=0;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j])
            {
                int s=0;
                for(int q=-1;q<=1;q++)
                    for(int w=-1;w<=1;w++)
                        if(w!=q&&w!=-q)
                            if(a[i+q][j+w])
                                s++;
                if(!s)
                {
                    t[i][j]=0;
                    a[i][j]=0;
                    ret=0;
                }
            }
        }
    }
    return ret;
}
void solve()
{
    /*cerr<<"DAY : "<<day<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cerr<<a[i][j]<<" ";
        }cerr<<endl;
    }
    getchar();//*/
    int mini=inf;
    int c[maxn][maxn];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            c[i][j]=0;
            if(a[i][j])
            {
                for(int q=-1;q<=1;q++)
                {
                    for(int w=-1;w<=1;w++)
                    {
                        if(q!=w&&q!=-w)
                            c[i][j]+=(a[i+q][j+w]!=0);
                    }
                }
                mini=min(mini,(f[i][j]-a[i][j])/c[i][j]);
            }
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            a[i][j]+=c[i][j]*mini;
    day+=mini;
    while(check3())
    {
        day++;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                a[i][j]+=c[i][j];
    }
}
main()
{
    cin>>n>>m>>k;
    po3[0]=1;
    po7[0]=1;
    for(int i=1;i<maxn;i++)
        po3[i]=(po3[i-1]*3)%m,po7[i]=(po7[i-1]*7)%m;
    a[1][1]=1;
    a[1][n]=1;
    a[n][1]=1;
    a[n][n]=1;
    build();
    while(check())
        solve();
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            ans=(ans+t[i][j])%mod;
            cerr<<t[i][j]<<" ";
        }cerr<<endl;
    }
    ans%=mod;
    cout<<ans<<" "<<(ans*ans*ans)%mod;
    return 0;
}
