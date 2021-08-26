#include <iostream>
#define int long long int
using namespace std;
int check(int x)
{
    for(int i=30;i>=0;i--)
        if(x>=(1<<i))
        return i;
}
main()
{
    int z=0,o=0;
    for(int i=1;i<=100000;i++)
    {
        for(int j=0;j<=check(i);j++)
        {
            if(i&(1<<j))
                o++;
            else
                z++;
        }
    }
    int a1=(o*(o-1)/2),a2=(z*(z-1)/2);
    cout<<a1+a2;
    return 0;
}
