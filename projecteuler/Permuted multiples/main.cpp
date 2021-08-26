#include <iostream>
#define int long long int
using namespace std;

main()
{
    bool b[10];
    for(int i=1;i<=10000000000;i++)
    {
        for(int j=0;j<10;j++)
            b[j]=0;
        int n=i;
        bool c=1;
        while(n)
        {
            b[n%10]=1;
            n/=10;
        }
        for(int j=2;j<=6;j++)
        {
            n=j*i;
            while(n)
            {
                if(b[n%10]==0)
                {
                    c=0;
                    j=7;
                    break;
                }
                n/=10;
            }
        }
        if(c)
            cout<<i<<endl;
    }
    return 0;
}
