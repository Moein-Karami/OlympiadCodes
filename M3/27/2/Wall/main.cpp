#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=229939,maxn=100;
int a[60][60];
vector<int> v[maxn];
int mark[maxn][maxn];
int cnt,t;
int tmp[10000];
int ran(int x,int y)
{
    return (123*x*x+1234*x+12345)%y;
}
void dfs(int x,int y)
{
    //cerr<<x<<" "<<y<<endl;
    //getchar();
    mark[x][y]=cnt;
    tmp[cnt]++;
    for(int i=-1;i<=1;i++)
    {
        for(int j=-1;j<=1;j++)
        {
            if(i!=j&&i!=-j)
            {
                if(i+x>=0&&j+y>=0)
                {
                    if(v[i+x].size()>y+j)
                    {
                        //cerr<<"SHIT"<<endl;
                        if(v[i+x][j+y]==v[x][y])
                        {
                            //cerr<<"FUCK"<<endl;
                            if(mark[i+x][j+y]!=cnt)
                                dfs(i+x,j+y);
                        }
                    }
                }
            }
        }
    }
}
main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            v[j].push_back(i*n+j+1);
    int t=n*n,s=n,l=0;
    int m=0;
    int ans=0;
    int ret=0;
    while(t)
    {
        l=0;
        for(int i=0;i<s;i++)
            for(int j=0;j<v[i].size();j++)
              ret=(ret+l*v[i][j])%mod,l++;
        m++;
        int z=ran(m,t);
        int x,y;
        for(int i=0;i<s;i++)
        {
            for(int j=0;j<v[i].size();j++)
            {
                if(z==0)
                {
                    x=i;
                    y=j;
                    i=s;
                    break;
                }
                z--;
            }
        }
        cnt++;
        //cerr<<t<<" "<<x<<" "<<y<<endl;
        //getchar();
        dfs(x,y);
        //cerr<<m<<endl;
        ans=(ans+tmp[cnt]*tmp[cnt]*tmp[cnt])%mod;
        for(int i=0;i<s;i++)
            for(int j=v[i].size()-1;j>=0;j--)
                if(mark[i][j]==cnt)
                    v[i].erase(v[i].begin()+j),t--;
        //cerr<<"SHIT"<<endl;
        for(int i=0;i<s;i++)
        {
            if(v[i].size()==0)
            {
                for(int j=i+1;j<s;j++)
                    swap(v[j],v[j-1]);
                s--;
            }
        }
    }
    cout<<ret;
    return 0;
}
