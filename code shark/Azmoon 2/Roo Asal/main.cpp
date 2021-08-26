#include <iostream>

using namespace std;
const int mod=11969;
int main()
{
    int ans=0;
    for(int i=2;i<=10;i++)
    {
        for(int j=2;j<=10;j++)
        {
            ans=(ans+(((i+1)*(j+1))*((i+1)*(j+1)-1)/2))%mod;
        }
    }
    cout<<ans;
    return 0;
}
