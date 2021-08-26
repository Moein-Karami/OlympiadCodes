#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=10009;
int solve(int l,int r)
{
    cout<<l<<" "<<r<<endl;
    if(l>=r||l+1==r)
        return 0;
    int t=3;
    for(int i=0;i<=50;i++)
    {
        if(t>r)
        {
            t/=2;
            return (t*t/3)%mod+solve(l,t-(t/3))%mod+solve(t+(t/3),r)%mod;
        }
        t*=2;
    }
}
main()
{
    cout<<solve(2,mod*mod)%mod;
    return 0;
}
