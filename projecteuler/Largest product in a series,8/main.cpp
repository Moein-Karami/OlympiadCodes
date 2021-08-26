#include <iostream>
#define int long long int
using namespace std;
int a[10000];
main()
{
    char c;
    for(int i=1;i<=1000;i++)
    {
        cin>>c;
        a[i]=c-'0';

    }
    int maxi=0;
    int t=1;
    for(int i=1;i<=1000;i++)
    {
        t=1;
        for(int k=0;k<13;k++)
            t*=a[i+k];
        maxi=max(maxi,t);
    }

    cout<<maxi;
    return 0;
}
