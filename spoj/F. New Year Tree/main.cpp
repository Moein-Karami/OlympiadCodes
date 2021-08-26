///Chefer


#include <bits/stdc++.h>
//#define int long long int
using namespace std;
const int maxn=1e6+10;
int u,v,ans;
int p[maxn][40];
int h[maxn];
int path(int x,int y)
{
    int ret=0;
    if(h[x]>h[y])
        swap(x,y);
    for(int i=29;i>=0;i--)
    {
        if(h[y]-(1<<i)>=h[x])
        {
            ret+=(1<<i);
            y=p[y][i];
        }
    }
    if(y==x)
        return ret;
    for(int i=29;i>=0;i--)
    {
        if(p[y][i]!=p[x][i])
        {
            ret+=(1<<i)*2;
            y=p[y][i];
            x=p[x][i];
        }
    }
    ret+=2;
    return ret;
}
main()
{
    //ios_base::sync_with_stdio(false);
    int n,t;
    cin>>n;
    u=2;
    v=3;
    ans=2;
    for(int i=2;i<=4;i++)
    {
        p[i][0]=1;
        h[i]=1;
    }
    t=4;
    int s;
    int t1 ,t2;
    for(int o=1;o<=n;o++)
    {
        scanf("%d",&s);
        h[t+1]=h[s]+1;
        h[t+2]=h[s]+1;
        p[t+1][0]=s;
        p[t+2][0]=s;
        for(int i=1;i<30;i++)
        {
            p[t+1][i]=p[p[t+1][i-1]][i-1];
            p[t+2][i]=p[p[t+2][i-1]][i-1];
        }
        t+=2;
        t1=path(t,u);
        t2=path(t,v);
        if(t2<t1)
        {
            if(t1>ans)
            {
                v=t;
                ans=t1;
            }
        }
        else
        {
            if(t2>ans)
            {
                u=t;
                ans=t2;
            }
        }
        printf("%d \n",ans);
        //cout<<ans<<"\n";
    }
    return 0;
}
