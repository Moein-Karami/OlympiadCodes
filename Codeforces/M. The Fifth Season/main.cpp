///Chefer



#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second

using namespace std;

main()
{
    int n,q,k,l;
    cin>>n>>q;
    for(int i=1;i<=q;i++)
    {
        cin>>k>>l;
        cout<<(n-l)/k+1<<" ";
    }
    return 0;
}
