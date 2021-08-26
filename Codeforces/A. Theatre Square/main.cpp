#include <iostream>

using namespace std;

int main()
{
    long long int n,m;
    cin>>n>>m;
    long long int a;
    cin>>a;
    long long int x,y;
    if(n%a!=0)
        x=n/a+1;
    else
        x=n/a;
    if(m%a!=0)
        y=m/a+1;
    else
        y=m/a;
        cout<<x*y;
    return 0;
}
