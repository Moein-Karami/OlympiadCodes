///Chefer


#include <Bits/stdc++.h>
#define int long long int
using namespace std;

main()
{
    int n,k,t;
    cin>>n>>k>>t;
    if(t<=n)
    {
        cout<<min(t,k);
        return 0;
    }
    cout<<k-(t-n);
    return 0;
}
