#include <bits/stdc++.h>
#define int long long unsigned int
using namespace std;
int mod=12917;
int f[1000];
int dp[100][20][20];
bool c[100][20][20];
vector<int> v;
int solve(int x,int y,int z)
{
    //cerr<<"X & Y & Z : "<<x<<" "<<y<<" "<<z<<endl;
    if(c[x][y][z])
        return dp[x][y][z];
    c[x][y][z]=1;
    if(y>=5)
        return 0;
    int &ret=dp[x][y][z];
    if(x==v.size()-2)
    {
        //cerr<<"SHIT"<<endl;
        if(y<=1&&z<=1)
            ret=1;
        return ret;
    }
    //cerr<<"II : X & Y & Z : "<<x<<" "<<y<<" "<<z<<endl;
    for(int i=1;i>=0;i--)
    {
        if(i<=y)
        {
            //cerr<<"I : "<<i<<endl;
            ret=(ret+solve(x+1,z+y-i,v[x+2]+y-i))%mod;
        }
        if(i==0)
            break;
    }
    //cerr<<"III : X & Y & Z : "<<x<<" "<<y<<" "<<z<<endl;
    return ret;
}
main()
{
    int x=1e18;
    x*=5;
    f[1]=1;
    f[2]=2;
    int cnt=2;
    while(f[cnt]<=x)
    {
        cnt++;
        f[cnt]=f[cnt-1]+f[cnt-2];
        //cerr<<cnt<<" "<<f[cnt]<<endl;
    }
    int n;
    cin>>n;
    cerr<<n<<endl;
    bool b=0;
    for(int i=cnt;i>=1;i--)
    {
        if(n>=f[i])
        {
            b=1;
            v.push_back(1);
            n-=f[i];
        }
        else if(b)
            v.push_back(0);
    }
    //cerr<<v.size()<<endl;
    //cerr<<"FUCK"<<endl;
    int ans=solve(0,v[0],v[1]);
    cout<<(ans*ans)%mod<<endl;
    return 0;
}
