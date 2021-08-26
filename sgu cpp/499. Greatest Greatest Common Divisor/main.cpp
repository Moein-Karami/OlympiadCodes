#include <bits/stdc++.h>

using namespace std;
int a[1000020];
int ans,t;
main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        for(int j=1;j*j<=t;j++)
        {
            if(t%j==0)
            {
                if(a[j])
                    ans=max(ans,j);
                a[j]++;
                if(j*j!=t)
                {
                    if(a[t/j])
                        ans=max(ans,t/j);
                    a[t/j]++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
