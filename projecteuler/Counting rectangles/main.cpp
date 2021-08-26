#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int inf=1e9;
main()
{
    int dif=inf,ans=0;
    for(int i=1;i<=3000;i++)
    {
        for(int j=1;j<=3000;j++)
        {
            int t=(i+1)*i*(j+1)*j/4;
            if(fabs(2000000-t)<dif)
            {
                dif=fabs(2000000-t);
                ans=(i*j);
            }
        }
    }
    cout<<ans<<" "<<dif;
    return 0;
}
