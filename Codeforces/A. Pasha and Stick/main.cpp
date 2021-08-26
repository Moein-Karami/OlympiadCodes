#include <iostream>

using namespace std;

int main()
{
    int n; cin>>n;
    if(n%2==1)
    {
        cout<<0;
        return 0;
    }

    int ans=n/4;
    if(ans*4==n)
        ans--;
    cout<<ans;
    return 0;
}
