#include <bits/stdc++.h>
#define int long long int
using namespace std;
int fib[3];
int mod=11161;
main()
{
    int m=1e13;
    int n=1378137813787;
    fib[0]=1;
    fib[1]=1;
    fib[2]=2;
    int i=2;
    bool b=1;
    while(b)
    {
        i++;
        if(i%3==0)
        {
            fib[0]=fib[1]+fib[2];
            fib[0]%=m;
            if(fib[0]==n)
            b=0;
        }
        else if(i%3==1)
        {
            fib[1]=fib[0]+fib[2];
            fib[1]%=m;
            if(fib[1]==n)
            b=0;
        }
        else if(i%3==2)
        {
            fib[2]=fib[0]+fib[1];
            fib[2]%=m;
            if(fib[2]==n)
            b=0;
        }
    }
    i++;
    cout<<i%mod<<endl;

    return 0;
}
