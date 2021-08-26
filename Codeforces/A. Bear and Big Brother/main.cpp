#include <iostream>

using namespace std;
#define int long long int
main()
{
    int a,b;
    cin>>a>>b;
    int s=0;
    while(a<=b)
    {
        s++;
        a*=3;
        b*=2;
    }
    cout<<s;
    return 0;
}
