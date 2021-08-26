#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n],p[n];
    p[-1]=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        p[i]=p[i-1]+a[i];
    }
    int cnt=0;
    for(int i=n-1;i>=0;i--)
    {
        cnt++;
        if(p[n-1]-p[i-1]>p[i-1])
            i=-1;
    }
    cout<<cnt;
    return 0;
}
