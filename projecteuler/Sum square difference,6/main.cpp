#include <iostream>

using namespace std;

int main()
{
    int ans1=0,ans2=0;
    for(int i=1;i<=100;i++)
        ans1+=i*i;
    for(int i=1;i<=100;i++)
        ans2+=i;
        ans2*=ans2;
    cout<<ans2-ans1;
    return 0;
}
