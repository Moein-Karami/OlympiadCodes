#include <bits/stdc++.h>
#define int long long int
using namespace std;

main()
{
    for(int i=1;i<=10000000;i++)
    {
        if(i*(8*i-12)+4>2000000000)
        {
            i--;
            cout<<i<<" "<<i*(8*i-12)+4<<" "<<2000000000-i*(8*i-12)-4<<endl;
            return 0;
        }
    }
    return 0;
}
