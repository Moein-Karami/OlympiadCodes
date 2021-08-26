#include <bits/stdc++.h>
#define int long long int
using namespace std;
int a[10][10][10];
int r[15][20];
int mod=10753;
void sat(int x)
{
    swap(a[x][1][2],a[x][2][1]);
    swap(a[x][2][1],a[x][3][2]);
    swap(a[x][3][2],a[x][2][3]);

    swap(a[x][1][1],a[x][3][1]);
    swap(a[x][3][1],a[x][3][3]);
    swap(a[x][3][3],a[x][1][3]);
}
void pad(int x)
{
    swap(a[x][1][2],a[x][2][3]);
    swap(a[x][2][3],a[x][3][2]);
    swap(a[x][3][2],a[x][2][1]);

    swap(a[x][1][1],a[x][1][3]);
    swap(a[x][1][3],a[x][3][3]);
    swap(a[x][3][3],a[x][3][1]);
}
void turn1(int x,int t1,int t2,int t3,int t4)
{
    int v[]={t1,t2,t3,t4};
    for(int i=3;i>0;i--)
    {
        for(int j=1;j<=3;j++)
        {
            if(i==3)
                swap(a[v[i]][4-j][4-x],a[v[i-1]][j][x]);
            else
                swap(a[v[i]][j][x],a[v[i-1]][j][x]);
        }
    }
}
void turn2(int x,int t1,int t2,int t3,int t4)
{
    int v[]={t1,t2,t3,t4};
    for(int i=3;i>0;i--)
        for(int j=1;j<=3;j++)
            swap(a[v[i]][x][j],a[v[i-1]][x][j]);
}
void turn0(int x,int t1,int t2,int t3,int t4)
{
    int v[]={t1,t2,t3,t4};
    for(int i=3;i>0;i--)
    {
        for(int j=1;j<=3;j++)
        {
            if(i==3)
                swap(a[v[i]][x][j],a[v[i-1]][j][4-x]);
            if(i==2)
                swap(a[v[i]][j][4-x],a[v[i-1]][4-x][j]);
            if(i==1)
                swap(a[v[i]][4-x][j],a[v[i-1]][j][x]);
        }
    }
}

main()
{
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            a[1][i][j]=(i-1)*3+j,a[6][i][j]=45+(i-1)*3+j;
    for(int i=2;i<=5;i++)
    {
        for(int j=1;j<=3;j++)
        {
            for(int k=1;k<=3;k++)
            {
                a[i][j][k]=(j-1)*12+9+(i-2)*3+k;
            }
        }
    }
    for(int i=1;i<=100;i++)
    {
        int x=0,y=0;
        for(int j=1;j<=i;j++)
            if(i%j==0)
                y++;
        y%=3;
        if(y!=1)
        {
            if(y==0)
            {
                if(x==1)
                    sat(2);
                if(x==2)
                    sat(6);
                if(x==0)
                    sat(5);
            }
            else
            {
                if(x==1)
                    pad(4);
                if(x==2)
                    pad(1);
                if(x==0)
                    pad(3);
            }
        }
        if(x==1)
            turn1(y+1,1,3,6,5);
        if(x==2)
            turn2(3-y,3,4,5,2);
        if(x==0)
            turn0(3-y,4,1,2,6);
    }
    int ans=0;
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            int t=(((i-1)*3+j)-a[1][i][j])%mod;
            t=(t*t)%mod;
            t=(t*t)%mod;
            ans=(ans+t)%mod;
            t=((45+(i-1)*3+j)-a[6][i][j]);
            t=(t*t)%mod;
            ans=(ans+t*t)%mod;
        }
    }
    for(int i=2;i<=5;i++)
    {
        for(int j=1;j<=3;j++)
        {
            for(int k=1;k<=3;k++)
            {
                int t;
                t=(((j-1)*12+9+(i-2)*3+k)-a[i][j][k])%mod;
                t=(t*t)%mod;
                ans=(ans+t*t)%mod;
            }
        }
    }
    cout<<ans;
    return 0;
}
