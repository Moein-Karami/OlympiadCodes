#include <bits/stdc++.h>
#define int long long int
using namespace std;
int b[10];
int tavan(int x)
{
    int ret=1;
    while(x)
        ret*=10,x/=10;
    return ret;
}
bool check(int x)
{
    for(int i=0;i<10;i++)
        b[i]=0;
    while(x)
    {
        b[x%10]+=1;
        x/=10;
    }
    bool ret =1;
    for(int i=1;i<=9;i++)
        if(b[i]!=1)
            ret=0;
        if(b[0])
            ret=0;
    return ret;
}
main()
{
    int t=0,ans=0;
    for(int i=1;i<100000;i++)
    {
        t=0;
        for(int j=1;j<=9;j++)
        {
            t=tavan(i*j)*t+i*j;
            if(t>10000000000)
                break;
            if(t>100000000&&t<10000000000)
                if(check(t))
                    ans=max(ans,t),cout<<t<<endl;
        }
    }
    cout<<ans;
    return 0;
}
