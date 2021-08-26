#include <bits/stdc++.h>
#define int long long int
using namespace std;
int f[12];
int mod=10513;
const int maxn=1e8;
int a[maxn];
main()
{
    f[0]=1;
    for(int i=1;i<12;i++)
        f[i]=i*f[i-1];
    int n;
    cin>>n;
    for(int i=1;i<=f[n];i++)
        a[i]=i;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=f[i];j++)
        {
            vector<int> v;
            int k=j;
            while(k<=f[n])
            {
                v.push_back(k);
                k+=f[i];
            }
            for(int e=v.size()-1;e>0;e--)
                swap(a[v[e]],a[v[e-1]]);
        }
    }
    int ans=0;
    for(int i=1;i<=f[n];i++)
    {
        //cerr<<a[i]<<" ";
        ans=(ans*(f[n]+3)+a[i])%mod;
    }
    //cerr<<endl;
    cout<<ans;
    return 0;
}
