#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod=10607;
int a[100];
main()
{
    int n;
    cin>>n;
    a[1]=1;
    for(int i=2;i<=n;i++)
    {
        a[i]=(1LL<<(i-1));
        for(int j=1;j<i;j++)
            if(i%j==0)
                a[i]-=a[j];
        cerr<<"I : "<<i<<" "<<a[i]<<endl;
    }
    int ret=(1LL<<n)-1;
    for(int i=1;i<=n;i++)
        ret-=a[i];
    cout<<ret%mod;
    return 0;
}
