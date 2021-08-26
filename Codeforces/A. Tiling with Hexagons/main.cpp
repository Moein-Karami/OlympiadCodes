///I'm Chefer now ;)


#include <bits/stdc++.h>
#define int long long int
using namespace std;

main()
{
    int a,b,c;
    cin>>a>>b>>c;
    a--;
    int t=(b+a)*(c+a);
    t-=a*(a+1);
    cout<<t;
    return 0;
}
