#include <iostream>
#define int long long int
using namespace std;
const int maxn=1e8+10;
int gcd[maxn];
main()
{
    int n,m;
    cin>>n>>m;
    gcd[1]=1;
    for(int i=2;i<=n;i++)
    {
        int a,b;
        a=n;
        b=i;
        while(a!=0&&b!=0)
        {
            if(a>b)
                a%=b;
            else
                b%=a;
        }
        gcd[i]=max(a,b);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        if(gcd[i]==1)
            ans++;
    ans*=(m/n);
    if(m%n!=0)
    {
        m%=n;
        for(int i=1;i<=m;i++)
            if(gcd[i]==1)
                ans++;
    }
    cout<<ans;
    return 0;
}
