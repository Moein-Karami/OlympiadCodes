#include <iostream>
#define int long long int
using namespace std;
int a[100][100];
int mod=10099;
main()
{
    a[0][0]=1;
    for(int i=1;i<=66;i++)
        a[i][0]=1;
    for(int i=1;i<=66;i++)
    {
        for(int j=1;j<=i;j++)
            a[i][j]=(a[i-1][j]+a[i-1][j-1])%mod;
    }
    cout<<a[66][33];
    return 0;
}
