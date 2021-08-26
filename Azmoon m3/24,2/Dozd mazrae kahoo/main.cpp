#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=10513;
int a[100000000];
int b[100000000];
int f[18];
int t(int x,int y)
{
    int ret=1;
    for(int i=0;i<=50;i++)
    {
        if(y&(1LL<<i))
            ret=(ret*x)%mod;
        x=(x*x)%mod;
    }
    return ret;
}
main()
{
    int n;
    cin>>n;
    f[0]=1;
    for(int i=1;i<=17;i++)
        f[i]=i*f[i-1];
    for(int i=1;i<=f[n];i++)
        a[i]=i,b[i]=i;
    for(int i=1;i<n;i++)
    {
        if(i%2==1)
        {
            for(int j=f[i]+1;j<=f[n];j++)
                b[j]=a[j-f[i]];
            for(int j=1;j<=f[i];j++)
                b[j]=a[f[n]-f[i]+j];
            //for(int j=1;j<=f[n];j++)
              //  cout<<b[j]<<" ";
            //cout<<endl;
        }
        else
        {
            for(int j=f[i]+1;j<=f[n];j++)
                a[j]=b[j-f[i]];
            for(int j=1;j<=f[i];j++)
                a[j]=b[f[n]-f[i]+j];
            //for(int j=1;j<=f[n];j++)
              //  cout<<a[j]<<" ";
            //cout<<endl;
        }
    }
    int m=(f[n]+3)%mod;
    int ans=0;
    for(int i=f[n];i>=1;i--)
    {
        b[i]%=mod;
        ans=(ans+b[i]*t(m,f[n]-i))%mod;
    }
    cout<<ans;
    return 0;
}
