#include <iostream>

using namespace std;

int main()
{
    int k2,k3,k5,k6,mini,ans=0,cnt=0;
    cin>>k2>>k3>>k5>>k6;
    mini=min(k2,k5);
    mini=min(mini,k6);
    ans+=mini*256;
    k2-=mini;
    while(k2!=0&&k3!=0)
    {
        k2--;
        k3--;
        cnt++;
    }
    ans+=cnt*32;
    cout<<ans;
    return 0;
}
