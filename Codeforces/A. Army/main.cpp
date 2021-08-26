#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=1;i<n;i++)
        cin>>a[i];
    int c,b;
    cin>>c>>b;
    int ans=0;
    for(int i=c;i<=b-1;i++)
        ans+=a[i];
    cout<<ans;
    return 0;
}
