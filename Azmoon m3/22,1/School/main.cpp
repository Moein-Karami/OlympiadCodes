#include <bits/stdc++.h>
#define f first
#define s second
#define int long long int
#define pii pair<int,int>
using namespace std;
const int mod=10009;
int a[mod*mod+10];
main()
{
    for(int i=1;i<=mod*mod+9;i++)
    {
        int t=i;
        while(t%2==0)
        {
            a[i]++;
            t/=2;
        }
    }
    pii m;
    int n=0;
    bool b=1;
    for(int i=1;i<=mod*mod;i++)
    {
        n+=a[i];
        n%=4;
        if(b&&n==1&&i/(1LL<<a[i])==3)
        {
             b=0;
             m.s-=666029;
        }
        else if(n==0)
        {
            m.s+=i/(1LL<<a[i]);
        }
        else if(n==1)
        {
            m.f+=i/(1LL<<a[i]);
        }
        else if(n==2)
        {
            m.s-=i/(1LL<<a[i]);
        }
        else
        {
            m.f-=i/(1LL<<a[i]);
        }
        if((m.f<-50&&m.f>-80)||(m.s<-666010&&m.s>-666030))
        cout<<i<<" "<<m.f<<" "<<m.s<<endl;
    }
    m.s%=mod;
    m.f%=mod;
    int ans=(m.s*m.f+m.s+m.f)%mod;

    return 0;
}
