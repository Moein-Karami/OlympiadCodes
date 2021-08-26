#include <iostream>

using namespace std;

int main()
{
    int n , z=0;
    cin>>n;
    if(n==0)
        z=1;
    else if(n==1)
        z=2;
    else
        z=4;
    for(int i=3 ; i<=n ; i++)
    {
       z+=i;
    }
    cout<<z;
    return 0;
}
