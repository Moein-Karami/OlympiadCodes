#include <iostream>

using namespace std;
bool np(int x)
{
    for(int i=2;i<=x/2;i++)
    {
        if(x%i==0)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int n;
    cin>>n;
    for(int i=4;i<=n-4;i++)
    {
        if(np(i)&&np(n-i))
        {
            cout<<i<<" "<<n-i;
            i=n;
        }
    }
    return 0;
}
