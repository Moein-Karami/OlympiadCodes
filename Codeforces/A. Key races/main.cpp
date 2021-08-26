#include <iostream>

using namespace std;

int main()
{
    int n,v1,v2,p1,p2;
    cin>>n>>v1>>v2>>p1>>p2;
    int y,x;
    y=(n*v1)+(2*p1);
    x=(n*v2)+(2*p2);
    if(y<x)
        cout<<"First";
    else if(x<y)
        cout<<"Second";
    else
        cout<<"Friendship";
    return 0;
}
