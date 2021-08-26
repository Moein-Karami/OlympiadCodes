#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod=10687;
const int maxn=1390;
bool b[maxn+20];
int cnt;
vector <int> v[maxn+20];
main()
{
    for(int i=1;i<=maxn;i++)
    {
        if(!b[i])
        {
            for(int j=i;j<=maxn;j*=2)
            {
                b[j]=1;
                v[cnt].push_back(j);
            }
            cnt++;
        }
    }
    int ans=1;
    for(int i=0;i<cnt;i++)
        ans=(ans*v[i].size())%mod;
    cout<<ans;
    return 0;
}
