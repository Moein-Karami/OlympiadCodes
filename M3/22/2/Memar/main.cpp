#include <bits/stdc++.h>

using namespace std;
bool b[1000];
int mod=10607;
main()
{
    int ans=1;
    for(int i=1;i<(1<<8);i++)
    {
        int x=0;
        int t=i;
        while(t)
        {
            x++;
            t/=2;
        }
        t=i;
        for(int j=2;j*x<=8;j++)
        {
            t=(t<<x);
            t+=i;
            if(b[t])
                continue;
            b[t]=1;
            ans=(ans*t)%mod;
        }
    }
    cout<<ans;
    return 0;
}
