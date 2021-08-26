#include <bits/stdc++.h>
#define int long long int
#define double long double
#define f first
#define s second
using namespace std;
typedef pair<int ,int> pii;
typedef pair<pii,double> pid;
const int mod=11969,maxn=1e3,maxm=2e7;
int dp[maxn][maxn][60];
map <double ,int>mp[maxn][maxn][4];
set<pii> se[maxm];
vector<pii> v;
int cnt=0;
int n,w,h,d;
int gcd(int x,int y)
{
    while(x&&y)
    {
        if(x<y)
            swap(x,y);
        x%=y;
    }
    return max(x,y);
}
int solve(int x,int y,int z)
{
    //cerr<<"X & Y & Z : "<<x<<" "<<y<<" "<<z<<" "<<d<<endl;
    if(z==0)
    {
        //cerr<<"shIT"<<endl;
        return 1;
    }
    if(x==v.size())
        return 0;
    int &ret=dp[x][y][z];
    if(ret!=-1)
        return ret;
    ret=solve(x+1,y,z);
    if(y==0)
    {
        ret=(ret+solve(x+1,x+1,z-1))%mod;
        return ret;
    }
    int f=fabs(v[x].f-v[y-1].f),s=fabs(v[x].s-v[y-1].s);
    int t=f*f+s*s;
    if(sqrt(t)>=d)
        ret=(ret+solve(x+1,x+1,z-1))%mod;
    return ret;
}
main()
{
    cin>>n>>w>>h>>d;
    for(int i=0;i<=w;i++)
    {
        cnt++;
        for(int j=0;j<=h;j++)
        {
            se[cnt].insert(pii(i,j));
        }
    }
    for(int j=0;j<=h;j++)
    {
        cnt++;
        for(int i=0;i<=w;i++)
        {
            se[cnt].insert(pii(i,j));
        }
    }
    double u,f,tp,c,gc;
    int t1,t2,t3,t4,m;
    for(double i=0;i<=w;i++)
    {
        for(double j=0;j<=h;j++)
        {
            for(double k=0;k<=w;k++)
            {
                for(double l=0;l<=h;l++)
                {
                    if(i!=k||j!=l)
                    {
                        f=k-i;
                        u=l-j;
                        if(f==0||u==0)
                            continue;
                        if(f*u>0)
                            tp=0;
                        else
                            tp=1;
                        c=(u/f)*i-j;
                        f=fabs(f);
                        u=fabs(u);
                        gc=gcd(f,u);
                        f/=gc;
                        u/=gc;
                        t1=f;
                        t2=u;
                        t3=tp;
                        if(!mp[t1][t2][t3][c])
                        {
                            cnt++;
                            mp[t1][t2][t3][c]=cnt;
                        }
                        m=mp[t1][t2][t3][c];
                        t1=i;
                        t2=j;
                        t3=k;
                        t4=l;
                        se[m].insert(pii(t1,t2));
                        se[m].insert(pii(t3,t4));
                    }
                }
            }
        }
    }
    set<pii>::iterator it;
    //cerr<<cnt<<endl;
    int ans=0;
    for(int i=1;i<=cnt;i++)
    {
        v.clear();
        it=se[i].begin();
        while(it!=se[i].end())
        {
            v.push_back(*it);
            it++;
        }
        sort(v.begin(),v.end());
        if(v.size()<n)
            continue;
        //cerr<<"I : "<<i<<endl;
        for(int j=0;j<=v.size()+4;j++)
        {
            //if(j<v.size())
              //  cerr<<v[j].f<<" "<<v[j].s<<endl;
            for(int l=0;l<=v.size()+4;l++)
                for(int k=0;k<=n;k++)
                    dp[j][l][k]=-1;
        }//cerr<<endl;
        ans=(ans+solve(0,0,n))%mod;
    }
    cout<<ans%mod;
    return 0;
}
