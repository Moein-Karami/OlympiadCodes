#include <iostream>
#include <algorithm>
using namespace std;
int a[10000];
int main()
{
    int n,s;
    cin>>n>>s;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        a[i]+=a[i-1];
    }
    if(a[n-2]<=s)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
