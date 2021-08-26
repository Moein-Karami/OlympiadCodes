#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<double,long long int> pii ;
long long int mod=10009;
pii e[1000001];
int main()
{
    for(int i=1;i<=1000000;i++)
        e[i].s=i;
    for(int i=2;i<=1000000;i++)
    {
        double t=1;
        for(int j=2;j*j<=i;j++)
        {
            if(i%j==0)
            {
                t+=j;
                if(i/j!=j)
                    t+=(i/j);
            }
        }
        if(t>=i)
        {
            double n=i;
            e[i].f=t/n;
        }
    }
    sort(e,e+1000001);
    for(int i=999987;i<=1000000;i++)
        cout<<e[i].f<<" "<<e[i].s<<endl;
    e[12].s=498960;
    e[12].s%=mod;
    cout<<(((e[12].s*e[12].s)%mod)+(((e[12].s*e[12].s)%mod)*e[12].s))%mod;
    return 0;
}
