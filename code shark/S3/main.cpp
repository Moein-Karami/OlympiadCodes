#include <bits/stdc++.h>
#define int long long int

using namespace std;
bool b[10][10];
bool dfs[10][10];
int ans;
int mod=22943;
void clean()
{
    for(int i=0;i<=5;i++)
        for(int j=0;j<=5;j++)
            b[i][j]=0,dfs[i][j]=0;b;
}
bool solve(int x,int y,int px,int py,int h)
{
    bool ret=0;
    if(x>4||x<0||y>4||y<0)
        return 0;
    if(x!=px||y!=py)
        if(b[x][y]&&b[px][py])
            return 0;
    if(b[x][y])
        h++;
    if(h>=3)
        return 0;
    if(x==4&&y==4&&h<3)
        return 1;
    ret=max(solve(x+1,y,x,y,h),solve(x,y+1,x,y,h));
    return ret;
}
main()
{
    for(int i=0;i<(1<<25);i++)
    {
        clean();
        for(int j=0;j<25;j++)
            if(i&(1<<j))
                b[j/5][j%5]=1;
        if(solve(0,0,0,0,0))
            ans++;
    }
    cout<<ans%mod;
    return 0;
}
