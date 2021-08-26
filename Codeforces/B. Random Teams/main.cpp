///DARK PROGRAMMER



#include <iostream>
#define ll long long int
using namespace std;
int k[1000000];
int main()
{
    ll n,m;
    cin>>n>>m;
    int b=n%m;
    cout<<(m)*(n/m)*(n/m-1)/2+b*(n/m);
    cout<<" "<<((n-m+1)*(n-m))/2;
    return 0;
}
