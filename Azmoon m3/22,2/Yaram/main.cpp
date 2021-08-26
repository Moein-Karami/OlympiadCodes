#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod =10607;
int m[mod+10];
int ans;
main()
{
    int a,b;
    for(int i=1;i<mod;i++)
    {
        for(int j=1;j*j<=i;j++)
        {
            if(i%j==0)
            {
                m[i]++;
                if(i/j!=j)
                    m[i]++;
            }
        }
    }
    for(int i=1;i<mod;i++)
    {
        for(int j=1;j<mod;j++)
        {
            a=j;
            b=i;
            while(b&&a)
            {
                if(a>b)
                    a%=b;
                else
                    b%=a;
            }
            if(m[max(a,b)]==48)
                ans++;
        }
    }
    int ret=1;
    for(int i=1;i<=ans;i++)
        ret=(ret*ans)%mod;
    cout<<ret;
    return 0;
}
