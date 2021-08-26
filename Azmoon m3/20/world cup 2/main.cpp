#include<bits/stdc++.h>

using namespace std;
double m[5][5];
double a[5];
int js[5][5];
int ps[5];
long double ans;
long double mod=10303;
int tavan(int x)
{
    int ret=1;
    for(int i=1;i<=x;i++)
        ret*=3;
    return ret;
}
void solve(int x)
{
    if(x==5)
    {
        for(int i=1;i<=4;i++)
            ps[i]=0;
        for(int i=1;i<=4;i++)
        {
            for(int j=1;j<=4;j++)
            {
                if(i!=j)
                {
                    if(js[i][j]==0)
                        ps[i]+=3;
                    if(js[i][j]==1)
                        ps[i]+=1;
                }
            }
        }
        if(ps[3]>ps[1]&&ps[3]>ps[2])
        {
            double t=1;
            for(int i=1;i<=4;i++)
            {
                for(int j=i+1;j<=4;j++)
                {
                    if(js[i][j]==0)
                        t*=((a[j]*(100-(m[i][j])))/(a[i]+a[j]));
                    if(js[i][j]==2)
                        t*=((a[i]*(100-(m[i][j])))/(a[i]+a[j]));
                    if(js[i][j]==1)
                        t*=(m[i][j]);
                    t/=100;

                }
            }ans+=t;
        }
        else if(ps[3]>ps[1]&&ps[3]>=ps[4])
        {
            double t=1;
            for(int i=1;i<=4;i++)
            {
                for(int j=i+1;j<=4;j++)
                {
                    if(js[i][j]==0)
                        t*=((a[j]*(100-(m[i][j])))/(a[i]+a[j]));
                    if(js[i][j]==2)
                        t*=((a[i]*(100-(m[i][j])))/(a[i]+a[j]));
                    if(js[i][j]==1)
                        t*=(m[i][j]);
                    t/=100;

                }
            }ans+=t;
        }
        else if(ps[3]>ps[2]&&ps[3]>=ps[4])
        {
            long double t=1;
            for(int i=1;i<=4;i++)
            {
                for(int j=i+1;j<=4;j++)
                {
                    if(js[i][j]==0)
                        t*=((a[j]*(100-(m[i][j])))/(a[i]+a[j]));

                    if(js[i][j]==2)
                        t*=((a[i]*(100-(m[i][j])))/(a[i]+a[j]));
                    if(js[i][j]==1)
                        t*=(m[i][j]);
                    t/=100;

                }
            }
            ans+=t;
        }
        return ;
    }
    for(int i=0;i<tavan(4-x);i++)
    {
        int t=i;
        int t1=x;
        while(t1<=4)
        {
            t1++;
            js[x][t1]=t%3;
            js[t1][x]=2-(t%3);
            t/=3;
        }
        solve(x+1);
    }
}
int main()
{
    a[1]=7;
    a[2]=13;
    a[3]=21;
    a[4]=30;
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
            m[i][j]=50-fabs(a[i]-a[j]);
    solve(1);
    ans=ans*mod*mod;
    int a=ans;
    cout<<a;
    return 0;
}
