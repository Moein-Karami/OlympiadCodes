///Expert


#include <iostream>
#define int long long int
using namespace std;
const int maxn =100000,mod =1e9+7;
int tavan[maxn];
main()
{
    tavan[0]=1;
    for(int i=1;i<maxn;i++)
        tavan[i]=(tavan[i-1]*26)%mod;
    string s;
    cin>>s;
    int n=s.size();
    int ans=0;
    for(int i=1;i<n;i++)
    {
        bool b=1;
        for(int j=1;j<n/i;j++)
        {b=0;
            if(n%i!=0)
            {
                b=1;
                break;
            }

            for(int k=0;k<i;k++)
            {

                if(s[k]!=s[k+(i*j)])
                {
                    b=1;
                    break;
                }
            }
            if(b)
                break;
        }
        ans=(ans+tavan[i])%mod;
        if(!b)
        {
            ans--;
        }
        ans=ans%mod;

    }
    cout<<ans%mod;
    return 0;
}
