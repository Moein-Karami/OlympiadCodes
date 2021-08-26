#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    long long int n , k=0;
    for(int j=1;j<=t;j++)
    {
        k=0;
        cin>>n;
        long long int ans=(n*(n+1))/2;
        for(long long int i=1;i<=n;i=i*2)
            k+=i;
        cout<<ans-2*k<<" ";
    }
    return 0;
}
