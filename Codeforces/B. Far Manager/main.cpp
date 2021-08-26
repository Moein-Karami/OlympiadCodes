///Chefer


#include <bits/stdc++.h>

using namespace std;

main()
{
    int p,n,x;
    cin>>p>>n>>x;
    int ans=0,ans2=0;
    if(x<p)
    {
        cout<<min(x,p-x);
        return 0
    }
    ans=x/p-1;
    ans+=min(1+x%p,)
    ans2=(n/p)+(n%p!=0);
    ans2+=(fabs((x%p)-(n%p)));
    ans2+=(n/p)-(x/p);
    cout<<min(ans,ans2);
    return 0;
}
