#include <bits/stdc++.h>
#define int long long int
using namespace std;

main()
{
    int n , k;
    cin>>n>>k;
    n-=(n%k);
    if((n/k)%2==1)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
