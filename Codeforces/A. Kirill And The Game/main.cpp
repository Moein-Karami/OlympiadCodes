///Chefer


#include <bits/stdc++.h>
#define int long long int
using namespace std;

main()
{
    int l,r,x,y,k;
    cin>>l>>r>>x>>y>>k;
    for(int i=x;i<=y;i++)
    {
        if(k*i<=r&&k*i>=l)
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}
