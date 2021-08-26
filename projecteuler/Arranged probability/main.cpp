#include <bits/stdc++.h>
#define int long long int
#define double long double
using namespace std;
int t=1e12;
int base=1e4;
struct bg
{
    int cnt;
    int a[30];
    void clean()
    {
        cnt=0;
        for(int i=0;i<30;i++)
            a[i]=0;
    }
    void fix()
    {
        for(int i=1;i<=cnt;i++)
        {
            a[i+1]+=a[i]/base;
            a[i]%=base;
            if(a[cnt+1])
                cnt++;
        }
    }
    void pro(int x)
    {
        for(int i=1;i<=cnt;i++)
            a[i]*=x;
        fix();
    }
    bool check(bg x)
    {
        if(cnt!=x.cnt)
            return (cnt>x.cnt);
        for(int i=1;i<=cnt;i++)
            if(a[i]!=x.a[i])
                return (a[i]>x.a[i]);
        return 1;
    }
    bool eq(bg x)
    {
        if(cnt!=x.cnt)
            return 0;
        for(int i=1;i<=cnt;i++)
            if(a[i]!=x.a[i])
                return 0;
        return 1;
    }
};
main()
{
    //cout<<fixed<<setprecision(60);
    //cerr<<fixed<<setprecision(60);
    int l,r,mid;
    while(t)
    {
        //cerr<<t;
        //getchar();
        l=1;
        r=t;
        bg c;
        c.clean();
        c.cnt=1;
        c.a[1]=1;
        //cerr<<"SHIT : "<<c.a[2]<<endl;
        c.pro(t);
        c.pro(t-1);
        //cerr<<"FUCK"<<endl;
        while(l+1!=r)
        {
            mid=(l+r)/2;
            //cerr<<mid<<endl;
            //getchar();
            bg b;
            b.clean();
            b.a[1]=1;
            b.cnt=1;
            b.pro(mid);
            b.pro(mid-1);
            b.pro(2);
            if(c.check(b))
                l=mid;
            else
                r=mid;
        }
        bg b;
        b.clean();
        b.a[1]=1;
        b.cnt=1;
        b.pro(l);
        b.pro(l-1);
        b.pro(2);
        if(c.eq(b))
        {
            cout<<l<<" "<<t;
            return 0;
        }
        t++;

    }
    return 0;
}
