#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod=12809;
int n,phi;
vector<int> v;
bool b[2234567];
int p(int x,int y)
{
    int ret=1;
    while(y)
    {
        if(y%2)
            ret=(ret*x)%n;
        y/=2;
        x=(x*x)%n;
    }
    return ret;
}
main()
{
    cin>>n;
    for(int i=1;i<n;i++)
        if(__gcd(i,n)==1)
            phi++;
    for(int i=1;i<=phi;i++)
        if(phi%i==0)
        v.push_back(i);
    int ans=0;
    for(int i=1;i<n;i++)
    {
        if(__gcd(i,n)==1)
        {
            int t=0;
            while(p(i,v[t])!=1)
                t++;
            ans+=v[t];
        }
        else
        {
            int t=0;
            int x=i;
            while(x&&!b[x])
            {
                t++;
                b[x]=1;
                x=(x*i)%n;
            }
            //cerr<<"I : "<<i<<" "<<t<<endl;
            ans+=t;
            x=i;
            for(int j=1;j<=t+3;j++)
            {
                b[x]=0;
                x=(x*i)%n;
            }
        }
    }
    cout<<ans<<" "<<ans%mod;
    return 0;
}
