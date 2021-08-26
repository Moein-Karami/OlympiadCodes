#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod=10567;
int dp[102][1002][5][5][5][5];
int solve(int x,int y,int t1,int t2,int t3,int t4)
{
    if(x>101)
        return 0;
    int a[]={-t1,-t2,-t3,-t4};
    sort(a,a+4);
    t1=-a[0];
    t2=-a[1];
    t3=-a[2];
    t4=-a[3];
    //cerr<<x<<" "<<y<<" "<<t1<<" "<<t2<<" "<<t3<<endl;
    int &ret=dp[x][y][t1][t2][t3][t4];
    if(ret!=-1)
        return ret;
    if(y==1001)
    {
        if(x==101&&t1==0)
            return 1;
        else
            return 0;
    }
    ret=solve(x,y+1,t1,t2,t3,t4);
    if(t1)
        ret=(ret+solve(x,y+1,0,t2,t3,t4))%mod;
    if(t2)
        ret=(ret+solve(x,y+1,t1,0,t3,t4))%mod;
    if(t3)
        ret=(ret+solve(x,y+1,t1,t2,0,t4))%mod;
    if(t4)
        ret=(ret+solve(x,y+1,t1,t2,t3,0))%mod;
    if(t1<4)
    {
        if(t1==0)
            ret=(ret+solve(x+1,y+1,1,0,0,0))%mod;
        else if(t2==0)
            ret=(ret+solve(x+1,y+1,t1+1,2,0,0))%mod;
        else if(t3==0)
            ret=(ret+solve(x+1,y+1,t1+1,t2+1,3,0))%mod;
        else
            ret=(ret+solve(x+1,y+1,t1+1,t2+1,t3+1,4))%mod;
    }
    return ret;
}
main()
{
    for(int i=0;i<102;i++)
        for(int j=0;j<1002;j++)
            for(int k=0;k<5;k++)
                for(int l=0;l<5;l++)
                    for(int q=0;q<5;q++)
                        for(int t=0;t<5;t++)
                            dp[i][j][k][l][q][t]=-1;
    cout<<solve(1,1,0,0,0,0);
    return 0;
}
