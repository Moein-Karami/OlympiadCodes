#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=1e9+7,del=10567;
int ans;
int po[10000000];
int pov(int x,int y)
{
    int ret=1;
    while(y)
    {
        if(y%2)
            ret=(ret*x)%mod;
        x=(x*x)%mod;
        y/=2;
    }
    return ret;
}
main()
{
    int n,k;
    cin>>n>>k;
    int t1=1,t2=1;
    for(int i=1;i<k;i++)
        t1=(t1*i)%k;
    for(int i=1;i<=n%k;i++)
        t2=(t2*i)%k;
    po[0]=1;
    for(int i=1;i<10000000;i++)
        po[i]=(po[i-1]*t1)%k;
    int x=1;
    int g=n/k;
    int m=n-n/k-1;
    int cnt=0;
    int d=(po[g]*t2)%k;
    for(int i=1;i<=n;i++)
    {
        //cerr<<"I : "<<i<<" "<<x<<endl;
        if(i%k==0)
            continue;
        ans=(ans+x*d)%mod;
        x=(((x*(m-cnt))%mod)*pov(cnt+1,mod-2))%mod;
        cnt++;
    }
    cout<<ans%del;
    return 0;
}
