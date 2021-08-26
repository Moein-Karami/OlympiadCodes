#include <iostream>
#define int long long int
using namespace std;
int a[3000000];
main()
{

    a[1]=1;
    int cnt=1;
    for(int i=1;i<=7830457;i++)
    {
        for(int j=1;j<=cnt;j++)
            a[j]*=2;
        for(int j=1;j<=cnt;j++)
        {
            if(a[j]>=10)
            {
                if(j==cnt)
                    cnt++;
                a[j+1]+=a[j]/10;
                a[j]%=10;
            }
        }
    }
    for(int i=1;i<=3000000;i++)
        a[i]*=28433;
    for(int i=1;i<=3000000;i++)
        {
            a[i+1]+=a[i]/10;
            a[i]%=10;
        }
    a[1]++;
    for(int i=10;i>=1;i--)
        cout<<a[i];
    return 0;
}
