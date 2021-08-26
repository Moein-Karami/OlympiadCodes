#include <iostream>

using namespace std;

int main()
{
    int n,w,k;
    cin>>k>>n>>w;
    int ans=(k*((w*w+w)/2))-n;
    if(ans<0)
        ans=0;
    cout<<ans;
    return 0;
}
