#include <bits/stdc++.h>
#define duble long long double
using namespace std;

main()
{
    double a=1,b=1;
    for(int i=61;i<=70;i++)
        b*=i;
    for(int i=41;i<=50;i++)
        a*=i;
    double s=a/b;
    s=(1.0L-s);
    cout<<fixed<<setprecision(9)<<" "<<s<<" "<<1.0L/s<<" "<<7.0L*(1.0L/s);
    return 0;
}
