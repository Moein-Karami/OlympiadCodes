#include <iostream>

using namespace std;

int main()
{
    int m , n , x ;
    cin>>m>>n;
    string a[n+1];
    for(int i=1; i<=n ;i++)
        cin>>a[i];
    x=m%n;
    if(x==0)
        x=n;
    cout<<a[x];
    return 0;
}
