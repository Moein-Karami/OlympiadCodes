///DARK PROGRAMMER


#include <iostream>

using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    int ans=0;
    while(a&&b)
    {
        ans++;
        a--;
        b--;
    }
    cout<<ans<<" "<<a/2+b/2;
    return 0;
}
