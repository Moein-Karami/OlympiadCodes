#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod=10711;
main()
{
    int t1=1,t2=1,t3=1,t4=1;
    for(int i=1;i<=1000;i++)
    {
        t1=(t1*4)%mod;
        t2=(t2*5)%mod;
        t3=(t3*3)%mod;
        t4=(t4*2)%mod;
    }
    cout<<(t2-t1-t3+t4+mod)%mod;
    return 0;
}
