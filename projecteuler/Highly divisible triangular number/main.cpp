#include <iostream>
#define int long long int
using namespace std;

main()
{
    for(int i=1;i<=100000;i++)
    {
        int n=i*(i+1)/2;
        int t=n;
        int cnt=0,ans=1;
        for(int j=2;j*j<=n;j++)
        {
            while(n%j==0)
            {
                n/=j;
                cnt++;
            }
            if(cnt)
            {
                cnt++;
                ans*=cnt;
            }
            cnt=0;
        }
        if(n>1)
            ans*=2;
        if(ans>=500)
        {
            cout<<t<<" "<<ans<<endl;
        }

    }
    return 0;
}
