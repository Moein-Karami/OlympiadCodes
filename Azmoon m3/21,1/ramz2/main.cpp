#include <bits/stdc++.h>
#define int long long int

using namespace std;

int mod=10487;
vector <int> v;
main()
{
    int x=mod*mod;
    cout<<x<<endl;
    v.push_back(1);
    while(x)
    {
        if(x%2==1)
            v.push_back(0);
        else
            v.push_back(1);
        x/=2;
    }
    v.push_back(0);
    int ans=0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==1)
        {
            ans+=(1<<(v.size()-i-1));
        }
    }
    cout<<ans;

    return 0;
}
