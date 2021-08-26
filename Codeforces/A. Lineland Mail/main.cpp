#include <iostream>

using namespace std;

int main()
{
    int n,mini=0,maxi=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
    {
        if(i!=0&&i!=n-1)
        {
          mini=min(-a[i-1]+a[i],-a[i]+a[i+1]);
          maxi=max(-a[0]+a[i],-a[i]+a[n-1]);
        }
        else if(i==0)
        {
            maxi=max(-a[0]+a[1],-a[0]+a[n-1]);
            mini=min(-a[0]+a[1],-a[0]+a[n-1]);
        }
        else if(i==n-1)
        {
            maxi=max(-a[0]+a[n-1],-a[0]+a[n-1]);
            mini=min(-a[0]+a[n-1],-a[n-2]+a[n-1]);
        }
        cout<<mini<<" "<<maxi<<endl;
    }
    return 0;
}
