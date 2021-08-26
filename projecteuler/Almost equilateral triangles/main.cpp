#include <bits/stdc++.h>
#define int long long int
using namespace std;
int inf=1e9;
main()
{
    int ans=0;
    for(int i=1;i<=inf/2+2;i++)
    {
        if(3*i+1<=inf)
            ans+=3*i+1;
        if(3*i-1<=inf)
            ans+=3*i-1;
    }
    cout<<ans;
    return 0;
}
