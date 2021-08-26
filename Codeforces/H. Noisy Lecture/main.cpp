#include <bits/stdc++.h>

using namespace std;

main()
{
    int n;
    cin>>n;
    int maxi=0,t;
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        maxi=max(maxi,t);
    }
    for(int i=1;i<=n;i++)
        cin>>t;
    int ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        ans+=t;
    }
    cout<<ans+n*maxi;
    return 0;
}
