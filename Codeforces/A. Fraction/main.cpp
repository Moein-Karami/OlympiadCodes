#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n%2==1)
    {
        cout<<n/2<<" "<<n/2+1;
    }
    else
    {
        int x=n/2;
        if(x%2==0)
            cout<<x-1<<" "<<x+1;
        else
            cout<<x-2<<" "<<x+2;
    }

    return 0;
}
