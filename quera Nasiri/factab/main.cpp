///DARK PROGRAMMER


#include <iostream>

using namespace std;
int aval[1000010];
int mod=1e9+7;
int main()
{
    int a,b;
    cin>>a>>b;
    for(int i=a+1;i<=b;i++)
    {
        int t=i;
        while(t%2==0)
        {
            aval[2]++;
            t/=2;
        }
        for( int j=3;j*j<=t;j+=2)
        {
            while(t%j==0)
            {
                aval[j]++;
                t=t/j;
            }
            if(t==1)
                break;
        }
        if(t>1)
        {
            aval[t]++;
        }

    }

    long long int ans=1;
    for(int i=2;i<=b;i++)
    {
        if(aval[i])
            ans=(ans*(aval[i]+1))%mod;
    }
    cout<<ans%mod;
    return 0;
}
