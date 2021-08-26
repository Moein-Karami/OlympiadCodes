#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn=2e6,mod=12809;
bool b[maxn];
int ans;
int gcd(int x,int y)
{
    while(x&&y)
    {
        if(x<y)
            swap(x,y);
        x%=y;
    }
    return max(x,y);
}
main()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        /*if(i>1&&gcd(i,n)==1)
        {
            ans+=n-1;
            continue;
        }//*/
        int t=i;
        while(!b[t]&&t)
        {
            b[t]=1;
            ans++;
            t=(t*i)%n;
        }
        t=i;
        while(b[t]&&t)
        {
            b[t]=0;
            t=(t*i)%n;
        }
    }
    cout<<ans%mod;
    return 0;
}
