#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n,c,d;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1)
            c=i;
        if(a[i]==n)
            d=i;
    }
    int maxi=max(fabs(c-n),fabs(c-1));
    int q=fabs(n-d);
    maxi=max(q,maxi);
    q=fabs(d-1);
    maxi=max(maxi,q);
    cout<<maxi;
    return 0;
}
