#include <iostream>

using namespace std;
bool b[4000020];
#define int long long int
main()
{
    b[1]=1;
    for(int i=2;i<=1999999;i++)
    {
        if(!b[i])
        {
            if(i*i<=2000000)
            {
                for(int j=i*i;j<=1999999;j+=i)
                {
                    b[j]=1;
                }
            }
        }
    }
    int sum=0;
    for(int i=1;i<=1999999;i++)
    {
        if(!b[i])
            sum+=i;
    }
    cout<<sum;
    return 0;
}
