#include <iostream>

using namespace std;
struct bg
{
    int a[10001];
    int cnt=0;
    void bet()
    {
        for(int i=0;i<=cnt;i++)
        {
            if(a[i]>=10)
            {
                if(i==cnt)
                {
                    cnt++;
                    a[i+1]+=(a[i]/10);
                    a[i]=a[i]%10;
                }
                else
                {
                    a[i+1]+=(a[i]/10);
                    a[i]=a[i]%10;
                }
            }
        }
    }
    void z(int x)
    {
        for(int i=0;i<=cnt;i++)
            a[i]*=x;
        bet();
    }
    bg()
    {
        for(int i=0;i<1000;i++)
            a[i]=0;
        a[0]=1;
    }
    void pr()
    {
        for(int i=cnt;i>=0;i--)
            cout<<a[i];
    }
    void jam(int x)
    {
        a[0]+=x;
        bet();
    }
    void jam_kharaki(bg m)
    {
        int maxi=max(cnt,m.cnt);
        for(int i=maxi;i>=0;i--)
            a[i]+=m.a[i];
        bet();
    }
};
bg operator+(bg a,bg b)
{
    a.jam_kharaki(b);
    return a;
}
bg sum;
int main()
{
    sum.a[0]=0;
    for(int j=1;j<=1000;j++)
    {
    bg n;
    int x=j,y=j;
    for(int i=1;i<=x;i++)
        n.z(y);
    sum.jam_kharaki(n);
    sum.bet();
    }
    sum.pr();
    //long long int sum=0;
    //n.bet();
    //for(int i=0;i<=n.cnt;i++)
        //sum+=n.a[i];
    //cout<<sum;
}
