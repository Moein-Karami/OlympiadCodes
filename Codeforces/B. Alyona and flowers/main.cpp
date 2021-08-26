#include <iostream>

using namespace std;
int a[1000],ans;
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    cin>>a[i];
    a[i]+=a[i-1];
    }
    int l,r;
    while(m--)
    {
        cin>>l>>r;
        if(a[r]-a[l-1]>=0)
        ans+=a[r]-a[l-1];

    }
    cout<<ans;
    return 0;
}
