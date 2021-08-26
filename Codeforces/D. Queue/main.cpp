///DARK PROGRAMMER


#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int ans=0,t=0;
    for(int i=0;i<n;i++)
    {
        if(t<=a[i])
        {
            t+=a[i];
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
