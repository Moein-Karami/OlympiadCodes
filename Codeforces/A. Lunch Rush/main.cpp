#include <iostream>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int maxi=-1e9;
    for(int i=1;i<=n;i++)
    {
        int l,t;
        cin>>l>>t;
        if(t<=k)
            maxi=max(maxi,l);
        else
            maxi=max(maxi,l-t+k);
    }
    cout<<maxi;
    return 0;
}
