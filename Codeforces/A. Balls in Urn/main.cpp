#include <iostream>

using namespace std;

main()
{
    int n,ans=0,t;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        ans=max(ans,t);
    }
    cout<<ans;
    return 0;
}
