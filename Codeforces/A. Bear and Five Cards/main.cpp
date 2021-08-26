#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a[5];
    for(int i=0;i<5;i++)
        cin>>a[i];
    sort(a,a+5);
    int sum=a[0]+a[1]+a[2]+a[3]+a[4];
    a[-1]=a[0]-1;
    int cnt=0,p=0,cnt2=0,mini=1e9;
    for(int i=3;i>=0;i--)
    {
        if(a[i]==a[i+1])
            mini=min(mini,sum-a[i]-a[i+1]);
         if(a[i]==a[i+1]&&a[i]==a[i-1])
        {
            mini=min(mini,sum-3*a[i]);
        }

    }
    if(mini!=1e9)
    cout<<mini;
    else
        cout<<sum;
    return 0;
}
