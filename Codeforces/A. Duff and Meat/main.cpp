#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n],p[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>p[i];
    }
    int mini=1e9;
    for(int i=0;i<n;i++)
    {
        if(p[i]>=mini)
            p[i]=mini;
        else
            mini=p[i];
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=a[i]*p[i];
    }
    cout<<ans;
    return 0;
}
