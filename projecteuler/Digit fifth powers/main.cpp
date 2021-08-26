#include <iostream>
#define int long long int
using namespace std;

main()
{
    int sum=0,ans=0,tmp,t;
    for(int i=2;i<=194979;i++)
    {
        sum=0;
        tmp=i;
        while(tmp)
        {
            t=tmp%10;
            sum+=(t*t*t*t*t);
            tmp/=10;
        }
        if(sum==i)
        {
            ans+=i;
            cout<<i<<" "<<ans<<endl;
        }
    }
    return 0;
}
