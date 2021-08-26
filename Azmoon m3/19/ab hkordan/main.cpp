#include <iostream>

using namespace std;
int a[1000000];
#define int long long int
 main()
{
    a[1]=1;
    int cnt=1;
    for(int i=1;i<=2010;i++)
    {
        for(int j=1;j<=cnt;j++)
            a[j]*=1388;
        for(int j=1;j<=cnt;j++)
        {
            if(j==cnt&&a[cnt]>=10)
            {
                a[cnt+1]+=a[cnt]/10;
                a[cnt]%=10;
                cnt++;
            }
            a[j+1]+=a[j]/10;
            a[j]%=10;
        }
    }
    int b=1;
    for(int i=1;i<=6;i++)
        b*=a[i];
    cout<<endl<<b%10099;
    return 0;
}
