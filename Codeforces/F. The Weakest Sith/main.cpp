///Chefer


#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn= 1e6,inf=1e9;
int a[maxn],b[maxn],c[maxn];
main()
{
    int n;
    cin>>n;
    int  mina=inf,minb=inf,minc=inf;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        mina=min(mina,a[i]);
        minb=min(minb,b[i]);
        minc=min(minc,c[i]);
    }
    int ans=0;
    vector <int> andis;
    for(int i=1;i<=n;i++)
    {
        if((a[i]<=mina&&b[i]<=minb)||(a[i]<=mina&&c[i]<=minc)||(c[i]<=minc&&b[i]<=minb))
        {
            ans++;
            andis.push_back(i);
        }
    }
    cout<<ans<<endl;
    for(int i=0;i<andis.size();i++)
    {
        cout<<andis[i]<<" ";
    }
    return 0;
}
