#include <bits/stdc++.h>

using namespace std;
int a[100];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n==1)
    {
        cout<<a[1]/2+1;
        return 0;
    }
    sort(a,a+n+1);
    int ans=0,sum=0;
    if(n%2==0)
    {
        for(int i=n;i>=n/2+1;i--)
            ans+=a[i];
        for(int i=1;i<=n/2;i++)
            sum+=(a[i]/2);
        ans+=sum;
    }
    else
    {
        for(int i=n;i>n/2+1;i--)
            ans+=a[i];
        for(int i=1;i<=n/2+1;i++)
            sum+=(a[i]/2);
        ans+=sum;
    }
    bool b=1;
    for(int i=1;i<=n;i++)
        if(a[i]%2==0)
            b=0;
    if(n%2==1)
        ans+=b;
    cout<<ans;
    return 0;
}
