#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=10631;
int ans;
main()
{
    bool b=1;
    for(int i=2;i*i<=13099;i++)
        if(13099%i==0)
                    b=0;
    cout<<b<<endl;
    int n;
    cin>>n;
    vector <int>v;
    v.push_back(0);
    for(int i=1;i<=n;i++)
        v.push_back(i);
    for(int i=2;i<=n;i++)
    {
        if(n%i==0)
        {
            for(int j=1;j<=n/i;j++)
            {
                for(int k=1;k<=i/2;k++)
                {
                    swap(v[(j-1)*i+k],v[i*j-k+1]);
                }
            }
        }
    }
    for(int i=1;i<v.size();i++)
        ans=(ans+i*v[i])%mod;
    cout<<ans;
    return 0;
}
