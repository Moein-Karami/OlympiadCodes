#include <iostream>

using namespace std;

int main()
{
    int n, s=0;
    cin>>n ;
    int a[n+1];
    a[0]=0;
    a[1]=1;
    for (int i=2 ;i<=n ;i++ )
        a[i]=a[i-1]+a[i-2];
    for(int i=1 ; i<=n ; i++)
        s+=a[i];
    cout<<s;
    return 0;
}
