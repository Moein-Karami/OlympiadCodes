#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod=10687;
main()
{
    int ans=0;
    for(int i=1;i<=81;i++)
    {
        vector<int> v;
        for(int j=1;j<=81;j++)
            v.push_back(j);
        int x=i-1;
        while(v.size()>1)
        {
            x+=22;
            x%=(v.size());
            v.erase(v.begin()+x);
        }
        if(v[0]==53)
        {
            ans=i;
            break;
        }
    }
    int ret=1;
    for(int i=1;i<=1390;i++)
        ret=(ret*ans)%mod;
    cout<<ret;
    return 0;
}
