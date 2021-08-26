#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    int ans=0;
    for(int i=1;i<=6;i++)
    {
        if(fabs(i-a)<fabs(i-b))
            ans++;
    }
    cout<<ans<<" ";
    ans=0;for(int i=1;i<=6;i++)
    {
        if(fabs(i-a)==fabs(i-b))
            ans++;
    }
    cout<<ans<<" ";
    ans=0;ans=0;for(int i=1;i<=6;i++)
    {
        if(fabs(i-a)>fabs(i-b))
            ans++;
    }
    cout<<ans<<" ";
    ans=0;
    return 0;
}
