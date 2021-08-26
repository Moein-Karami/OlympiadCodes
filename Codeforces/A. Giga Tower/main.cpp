///DARK PROGRAMMER


#include <iostream>
#define int long long int
using namespace std;

main()
{
    int n;
    cin>>n;
    for(int i=1;i<=1000000;i++)
    {
        int t=n;
        t+=i;
        if(t<0)
            t=-t;
        while(t)
        {
            if(t%10==8)
            {
                cout<<i;
                return 0;
            }
            t/=10;
        }
    }
    return 0;
}
