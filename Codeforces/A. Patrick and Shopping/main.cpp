#include <iostream>

using namespace std;

int main()
{
    int a,b,c,mini=1e9+7,mini1=1e9+7;
    cin>>a>>b>>c;
    mini1=min(a,b);
    mini=min(a+b+c,2*(a+b));
    mini=min(mini,2*(c+mini1));
    cout<<mini;
    return 0;
}
