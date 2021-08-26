///Chefer


#include <bits/stdc++.h>
#define int long long int
using namespace std;

main()
{
    int n,k;
    cin>>n>>k;
    int t=1;
    for(int i=1;i<=k;i++)
        t*=10;
    int ans=t*n;
    while(n&&t)
    {
        if(n<t)
            swap(n,t);
        n%=t;
    }
    cout<<ans/(max(t,n));
    return 0;
}
