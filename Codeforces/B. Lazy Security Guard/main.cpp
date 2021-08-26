///Chefer


#include <bits/stdc++.h>

using namespace std;

main()
{
    int n;
    cin>>n;
    int s=sqrt(n);
    cout<<4*s+((n-s*s)/s+((n-s*s)%s!=0))*2;
    return 0;
}
