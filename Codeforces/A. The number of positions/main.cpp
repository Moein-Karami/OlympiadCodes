///DARK PROGRAMMER


#include <iostream>

using namespace std;

int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    int ans=0;
    for(int i=0;i<=b;i++)
        if(n-i-1>=a)
            ans++;
    cout<<ans;
    return 0;
}
