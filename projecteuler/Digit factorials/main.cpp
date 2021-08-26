#include <iostream>
#define int long long int
using namespace std;
int fact[10];
main()
{
    int sum=0,ans=0,tmp,t;
    fact[0]=1;
    for(int i=1;i<=9;i++)
        fact[i]=i*fact[i-1];
    for(int i=3;i<=10000000000;i++)
    {
        sum=0;
        tmp=i;
        while(tmp)
        {
            t=tmp%10;
            sum+=fact[t];
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
