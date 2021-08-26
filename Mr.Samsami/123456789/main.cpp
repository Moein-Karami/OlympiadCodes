#include <bits/stdc++.h>
#define int long long
using namespace std;
vector <int> v;
main()
{
    int t=123456789;
    for(int i=32;i>=0;i--)
    {
        if(t&(1<<i))
            v.push_back(1);
        else
            v.push_back(0);
    }
        for(int i=0;i<v.size();i++)
            cout<<v[i];
        cout<<endl;
    int n=0;
    n=(1LL<<32)+(1LL<<31)+(1LL<<30)+(1LL<<29)+(1LL<<26)+(1LL<<25)+(1LL<<23)+(1LL<<19)+(1LL<<17)+(1LL<<15)+(1LL<<14)+(1LL<<8)+(1LL<<7)+(1LL<<6)+(1LL<<4)+(1LL<<2)+(1LL<<1);
    cout<<n;
    return 0;
}
