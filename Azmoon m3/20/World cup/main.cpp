#include <bits/stdc++.h>

using namespace std;
double a[5];
double m[5][5];
int score[5][5];
int person[5];
double ans;
double tmp1,tmp2;
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
        if(person[3]>person[1]&&person[3]>person[2])
        {
            tmp1=1;
            for(int i=1;i<=4;i++)
            {
                for(int j=i+1;j<=4;j++)
                {
                    if(score[i][j]==0)
                        tmp1*=((a[j]*(100-m[i][j]))/a[i]+a[j]);
                    else if(score[i][j]==1)
                        tmp1*=((a[i]*(100-m[i][j]))/a[i]+a[j]);
                    else
                        tmp1*=m[i][j]/100;
                }
            }
            ans+=tmp1;
        }
        else if(person[3]>person[1]&&person[3]>=person[4])
        {
            tmp1=1;
            for(int i=1;i<=4;i++)
            {
                for(int j=i+1;j<=4;j++)
                {
                    if(score[i][j]==0)
                        tmp1*=((a[j]*(100-m[i][j]))/a[i]+a[j]);
                    else if(score[i][j]==1)
                        tmp1*=((a[i]*(100-m[i][j]))/a[i]+a[j]);
                    else
                        tmp1*=m[i][j]/100;
                }
            }
            ans+=tmp1;
        }
        else if(person[3]>person[2]&&person[3]>=person[4])
        {
            tmp1=1;
            for(int i=1;i<=4;i++)
            {
                for(int j=i+1;j<=4;j++)
                {
                    if(score[i][j]==0)
                        tmp1*=((a[j]*(100-m[i][j]))/a[i]+a[j]);
                    else if(score[i][j]==1)
                        tmp1*=((a[i]*(100-m[i][j]))/a[i]+a[j]);
                    else
                        tmp1*=m[i][j]/100;
                }
            }
            ans+=tmp1;
        }
        return ;
    }
    for(int i=0;i<tavan(4-x);i++)
    {
        int t=i,t1=x;
        while(t)
        {
            t1++;
            score[x][t1]=t%3;
            if(t%3==0)
                person[x]+=3;
            else if((t%3)==2)
            {
                person[x]+=1;
                person[t1]+=1;
            }

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
            m[i][j]=(50-fabs(a[i]-a[j]));
    for(int i=0;i<=26;i++)
    {
         clean
        int t=i,t1=1;
        while(t)
        {
            t1++;
            score[1][t1]=t%3;
            if(t%3==0)
                person[1]+=3;
            else if((t%3)==2)
            {
                 person[1]+=1;
                 person[t1]+=1;
            }

            t/=3;
        }
        solve(2);
    }
    cout<<ans;
    return 0;
}
