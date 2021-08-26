#include <iostream>

using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    a=max(a,b);
    int e=6-a+1,k=6;
    if(e%2==0)
    {
        e/=2;
        k/=2;
    }
    if(e%3==0)
    {
        e/=3;
        k/=3;
    }
    cout<<e<<"/"<<k;
    return 0;
}
