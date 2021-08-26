#include <iostream>

using namespace std;
int a[10000],b[10000],c[10000];
int main()
{
    int n , x ;
    cin >>n>>x;
    x++;
    for (int i=0;i<n;i++)
        cin>>a[i];
    for (int i=0 ; i<n ; i++)
    {
        b[a[i]]++;
    }

    for(int i=0;i<x;i++)
    {
            b[i]+=b[i-1];
    }

    for (int i=n-1 ; i>=0;i--)
    {
        b[a[i]]--;
        c[b[a[i]]]=a[i];
    }
    for(int i=0;i<n;i++)
        cout << c[i]<<" ";
    return 0;
}
