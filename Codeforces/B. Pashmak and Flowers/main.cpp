#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long int n;
    cin>>n;
    long long int a[n];
    long long int maxi=0,mini=1e9;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>maxi)
            maxi=a[i];
        if(a[i]<mini)
            mini=a[i];
    }
    sort(a,a+n);
    cout<<maxi-mini<<" ";
    long long int cnt1=0,cnt2=0;
    if(maxi!=mini)
    {
            for(int i=0;i<n;i++)
        {
            if(a[i]==mini)
                cnt2++;
            if(a[i]==maxi)
                cnt1++;
        }
        cout<<cnt1*cnt2;
    }
    else
        cout<<n*(n-1)/2;
    return 0;
}
