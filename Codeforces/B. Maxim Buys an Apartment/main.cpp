///Chefer


#include <bits/stdc++.h>

using namespace std;

main()
{
    int n,k;
    cin>>n>>k;
    if(k!=n&&k!=0)
        cout<<1<<" ";
    else
        cout<<0<<" ";
    if(k<=n/3)
    {
        cout<<2*k;
        return 0;
    }
    if(n%3==0)
    {
        int ans= n-(n/3);
        k-=(n/3);
        cout<<max(0,ans-k);
        return 0;
    }
    if(n%3==1)
    {
        int ans= n-(n/3);
        k-=(n/3);
        k--;
        ans--;
        cout<<max(0,ans-k);
        return 0;
    }
    if(n%3==2)
    {
        int ans= n-(n/3);
        k-=(n/3);
        k--;
        ans--;
        cout<<max(0,ans-k);
        return 0;
    }
    return 0;
}
