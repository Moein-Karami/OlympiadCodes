///DARK PROGRAMMER


#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int maxi=0,j=0;
    maxi=a[n-1];
    int s=2*k-n;
    for(int i=n-1-s;i>=0;i--)
    {
        if(i<=j)
            break;
        if(a[j]+a[i]>maxi)
            maxi=a[i]+a[j];
        j++;
    }
    cout<<maxi;
    return 0;
}
