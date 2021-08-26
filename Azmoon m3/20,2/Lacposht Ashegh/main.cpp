#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
pii a,b,c;
int mod=10009;
pii ta,tb,tc;
int main()
{
     a.f=1024;
     a.s=2010;
     b.f=-1381;
     b.s=138;
     c.f=1;
     c.s=2010;
     int s=0;
     bool w=1;
     while(w)
     {
         ta.f=0;
         ta.s=0;
         tb.f=0;
         tb.s=0;
         tc.f=0;
         tc.s=0;
         w=0;
         s++;
         if(fabs(a.f-b.f)>1||fabs(a.s-b.s)>1)
         {
             w=1;
            if(b.f>a.f)
                ta.f++;
            if(b.f<a.f)
                ta.f--;
            if(b.s<a.s)
                ta.s--;
            if(b.s>a.s)
                ta.s++;
         }
         if(fabs(b.f-c.f)>1||fabs(b.s-c.s)>1)
         {
             w=1;
            if(c.f>b.f)
                tb.f++;
            if(c.f<b.f)
                tb.f--;
            if(c.s<b.s)
                tb.s--;
            if(c.s>b.s)
                tb.s++;
         }
         if(fabs(a.f-c.f)>1||fabs(a.s-c.s)>1)
         {
             w=1;
            if(a.f>c.f)
                tc.f++;
            if(a.f<c.f)
                tc.f--;
            if(a.s<c.s)
                tc.s--;
            if(a.s>c.s)
                tc.s++;
         }
         a.f+=ta.f;
         a.s+=ta.s;
         b.f+=tb.f;
         b.s+=tb.s;
         c.f+=tc.f;
         c.s+=tc.s;
         cout<<a.f<<" "<<a.s<<endl;
         cout<<b.f<<" "<<b.s<<endl;
         cout<<c.f<<" "<<c.s<<endl<<endl;
     }
     s--;
     int ans=1;
     for(int i=1;i<=6;i++)
        ans=(ans*s)%mod;
     cout<<ans%mod;
    return 0;
}
