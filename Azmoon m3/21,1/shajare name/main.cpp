#include <bits/stdc++.h>
#define int long long int
using namespace std;
bool p[30000];
const int mod= 10487;
int h[mod+10];
int solve(int p, int x)
{
    h[x]=h[p]+1;
    if(x/2>0&&x/2!=p)
        solve(x,x/2);
    if(x*2<=mod&&x*2!=p)
        solve(x,x*2);
    if(x*2+1<=mod&&x*2+1!=p)
        solve(x,x*2+1);
}
main()
{
    cout<<247155232%mod;
    char c;
    cin>>c;
    p[1]=1;
    for(int i=2;i<30000;i++)
    {
        if(!p[i])
        {
            for(int j=i*i;j<30000;j+=i)
                p[j]=1;
        }
    }
    int ans=1;
    for(int i=2;i<=mod;i++)
    {
        for(int j=i+1;j<=mod;j++)
        {
            if(!p[i]&&!p[j]&&!p[i+j+1])
            {
                h[i]=-1;
                solve(i,i);
                ans=(ans*h[j])%mod;
            }
        }
    }
    cout<<ans%mod;
    return 0;
}
