#include <bits/stdc++.h>
#define int long long int
using namespace std;
bool check(int x)
{
    for(int i=2;i*i<=x;i++)
        if(x%i==0)
            return 0;
    return 1;
}
main()
{
    int t=0;
    for(int i=2;i<=100000;i++)
    {
        int x=2*i-1;
        x*=x;
        if(check(x))
            t++;
        x-=2*i-2;
        if(check(x))
           t++;
        x-=2*i-2;
        if(check(x))
            t++;
        x-=2*i-2;
        if(check(x))
            t++;
        int s=4*i-3;
        if(10*s>=100*t)
        {
            cout<<2*i-1;
            return 0;
        }
    }
    return 0;
}
