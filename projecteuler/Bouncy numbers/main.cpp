#include <bits/stdc++.h>
#define int long long int
using namespace std;

main()
{
    int ans=0;
    for(int i=100;i<=1000000000;i++)
    {
        int t=i;
        bool b0=0,b1=0;
        while(t)
        {
            int s=t%10;
            t/=10;
            if(t)
            {
                if(s>t%10)
                    b0=1;
                else if(s<t%10)
                    b1=1;
            }
        }
        if(b0&&b1)
            ans++;
        if(ans*100==i*99)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}
