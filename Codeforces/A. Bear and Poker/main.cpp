///DARK PROGRAMMER



#include <iostream>
#include <vector>
#define int long long int

using namespace std;
main()
{
    int n;
    cin>>n;
    int b;
    cin>>b;
    while(b%2==0)
        b/=2;
    while(b%3==0)
        b/=3;
    int t=b;
    for(int i=1;i<n;i++)
    {
        cin>>b;
        while(b%2==0)
            b/=2;
        while(b%3==0)
            b/=3;
        if(b!=t)
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}
