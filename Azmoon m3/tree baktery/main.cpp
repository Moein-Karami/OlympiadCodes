#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int d=10559;
const int mod=1e9+7;
int tarkib(int x,int y)
{
    int a=1;
    for(int i=y;i>y-x;i--)
        a=(a*i)%mod;
    int b=1;
    for(int i=1;i<=x;i++)
        b=(b*i)%mod;
    for(int i=0;i<32;i++)
    {
        if((mod-2)&(1LL<<i))
            a=(a*b)%mod;
        b=(b*b)%mod;
    }
    return a;
}
main()
{
    int a=tarkib(5,32)%d;
    int b=tarkib(4,31-4)%d;
    cout<<(a*b)%d;
    return 0;
}
