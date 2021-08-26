#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=10949;
int d=1e9+7,da=1e8;
int a[110][110],t[110][110],f[110][110],se[110],haft[110],tmp[110][110];
int x;
main()
{
    se[0]=1;
    haft[0]=1;
    for(int i=1;i<=100;i++)
    {
        se[i]=(3*se[i-1])%d;
        haft[i]=(7*haft[i-1])%d;
    }
    for(int i=1;i<=100;i++)
    {
        for(int j=1;j<=100;j++)
            f[i][j]=da+((haft[i]*se[j])%d);
    }
    cin>>x;
    for(int i=0;i<=x+1;i++)
    {
        for(int j=0;j<=x+1;j++)
            if(j==0||i==0||j==x+1||i==x+1)
                t[i][j]=1000000000000LL;
    }
    tmp[1][1]=1;
    tmp[x][1]=1;
    tmp[1][x]=1;
    tmp[x][x]=1;
    bool b=1;
    int cnt=0;
    while(b)
    {
        for(int i=1;i<=x;i++)
        {
            for(int j=1;j<=x;j++)
                a[i][j]=tmp[i][j];
        }
        b=0;
        cnt++;
        for(int i=1;i<=x;i++)
        {
            for(int j=1;j<=x;j++)
            {
                if(a[i][j]&&(!t[i][j]||t[i][j]==cnt))
                {
                    for(int q=-1;q<=1;q++)
                    {
                        for(int w=-1;w<=1;w++)
                        {
                            if(q!=w&&q!=-w)
                            {
                                if(!t[i+q][w+j]||t[i][j]==cnt)
                                {
                                    b=1;
                                    tmp[i+q][w+j]++;
                                    if(f[i+q][w+j]==tmp[i+q][w+j])
                                    {
                                        t[i+q][w+j]=cnt;
                                        tmp[i+q][w+j]=0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<=x;j++)
            ans=(ans+t[i][j])%mod;
    }
    int ret=1;
    for(int i=1;i<=3;i++)
        ret=(ret*ans)%mod;
    cout<<ret;
    return 0;
}
