#include <iostream>

using namespace std;

int main()
{
    int n,ans=0;
    cin>>n;
    int x,y;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        if(y>=x+2)
            ans++;
    }
    cout<<ans;
    return 0;
}
