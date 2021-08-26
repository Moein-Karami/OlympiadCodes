///Chefer


#include <bits/stdc++.h>
#define double long double
using namespace std;
int ans;
main()
{
    double R,r,d;
    cin>>R>>d;
    r=R-d;
    double n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        double x,y,m;
        cin>>x>>y>>m;
        x=fabs(x);
        y=fabs(y);
        double vatar=x*x+y*y;
        vatar=sqrt(vatar);
        if(m+r>vatar)
            continue;
        if(R>=vatar+m)
            ans++;
    }
    cout<<ans;
    return 0;
}
