///Chefer


#include <bits/stdc++.h>

using namespace std;

main()
{
    std::cout<<std::fixed;
    std::cout<<std::setprecision(7);
    double x,y,m;
    cin>>x>>y>>m;
    double t=y-x;
    t*=60;
    double k=m/t;
    k=1-k;
    cout<<1-(k*k);
    return 0;
}
