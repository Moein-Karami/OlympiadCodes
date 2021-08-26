#include <bits/stdc++.h>
//#define int long long int ;
int mod=12263;
using namespace std;
int gcd(int x,int y)
{
    while(x&&y)
    {
        if(x<y)
            swap(x,y);
        x%=y;
    }
    return max(x,y);
}
main()
{
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            if((i+j)%2==0)
            {
                if(gcd(i,j)==gcd((i+j)/2,(i-j)/2))
                    ans=(ans+1)%mod;
            }
        }
    }
    cout<<ans;
    return 0;
}
