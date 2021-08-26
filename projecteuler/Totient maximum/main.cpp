#include <iostream>
#define int long long int
using namespace std;

main()
{
    int n=1;
    char k;
    for(int i=2;i<=1000000;i++)
    {
        bool c=1;
        for(int j=2;j*j<=i;j++)
            if(i%j==0)
                c=0;
        if(c)
        {
            n*=i;
            cout<<n<<endl;;
            cin>>k;
        }
    }
    return 0;
}
