#include <iostream>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int ans=0;
    int q=a[k-1];
    if(a[k-1]==0)
        q++;
    for(int i=0;i<n;i++)
        if(a[i]>=q)
        ans++;
    cout<<ans;

    return 0;
}
