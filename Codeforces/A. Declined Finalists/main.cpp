#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int maxi=0;
    for(int i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        maxi=max(t,maxi);
    }
    cout<<max(maxi-25,0);
    return 0;
}
