#include <iostream>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int x;
    if(n%k>0)
    {
        x=n+(k-(n%k));
    }
    else
    {
        x=n+k;
    }
    cout<<x;
    return 0;
}
