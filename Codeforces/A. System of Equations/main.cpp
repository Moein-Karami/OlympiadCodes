#include <iostream>

using namespace std;
int ans;
int main()
{
    int a,b;
    cin>>a>>b;
    for(int i=0;i<1000;i++)
    {
        for(int j=0;j<1000;j++)
        {
            if((i*i)+j==a&&i+(j*j)==b)
                ans++;
        }
    }
    cout<<ans;
    return 0;
}
