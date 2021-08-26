///Chefer


#include <bits/stdc++.h>
#define int unsigned int
#define f first
#define s second
#define rand() rand()*rand()%mod
using namespace std;
typedef pair<int,int> pii;
const int maxn=3e5+10,mod=1e9+9;
int fibo[maxn];
int a[maxn];
int seg[1000+1];
pii hint[1000+1];
int tmp[maxn];
main()
{
    ios_base::sync_with_stdio(false);
    fibo[1]=1;
    fibo[2]=1;
    int n,q;
    cin>>n>>q;
    //n=300000;
    //q=300000;
    int tp,l,r,t,i,j,ans,t2,o;
    for(i=1;i<=n;i++)//a[i]=rand();
        cin>>a[i];
    int s=sqrt(n);
    for( i=3;i<=n+10;i++)
    {
        fibo[i]=(fibo[i-1]+fibo[i-2])%mod;
    }
    for(i=1;i<=n/s+(n%s!=0);i++)
    {
        for(j=(i-1)*s+1;j<=min(i*s,n);j++)
            seg[i]=(seg[i]+a[j])%mod;
    }
    for(o=1;o<=q;o++)
    {
        cin>>tp>>l>>r;
        //tp=rand()%2;
        //l=rand()%n;
        //r=rand()%n;
        //if(r<l)
          //  swap(l,r);
        t=l/s+(l%s!=0),t2=r/s-(r%s==0);

        if(tp==1)
        {

            for(i=l;i<=min(t*s,r);i++)
                a[i]=(a[i]+fibo[i-l+1])%mod,seg[t]=(seg[t]+fibo[i-l+1])%mod;
            t++;
            for(i=t;i<=t2;i++)
            {
                seg[i]=(seg[i]+fibo[i*s-l+3]-fibo[(i-1)*s-l+3]+mod)%mod;
                hint[i].f=(hint[i].f+fibo[(i-1)*s-l+1+1])%mod;
                hint[i].s=(hint[i].s+fibo[(i-1)*s-l+1+2])%mod;
            }
            t--;
            if(t2>=t)
            {
                for(i=s*t2+1;i<=r;i++)
                {
                    seg[t2+1]=(seg[t2+1]+fibo[i-l+1])%mod;
                    a[i]=(a[i]+fibo[i-l+1])%mod;
                }
            }
        }
        else
        {
            ans=0;
            t--;
            tmp[s*t+1]=hint[t+1].f;
            tmp[s*t+2]=hint[t+1].s;
            for(i=s*t+3;i<=s*(t+1);i++)
                tmp[i]=(tmp[i-1]+tmp[i-2])%mod;
            t++;
            for(i=l;i<=min(r,t*s);i++)
                ans=(ans+a[i]+tmp[i])%mod;
            t++;
            for(i=t;i<=t2;i++)
                ans=(ans+seg[i])%mod;
            tmp[(t2)*s+1]=hint[t2+1].f;
            tmp[(t2)*s+2]=hint[t2+1].s;
            for(i=s*t2+3;i<=r;i++)
                tmp[i]=(tmp[i-1]+tmp[i-2])%mod;
            t--;
            if(t2>=t)
                for(i=s*t2+1;i<=r;i++)
                    ans=(ans+a[i]+tmp[i])%mod;
            cout<<ans<<"\n";
        }
    }
    return 0;
}
