#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int x=max(a*b*c,a+b+c);
    x=max(x,(a+b)*c);
    x=max(x,(a*b)+c);
    x=max(x,a+(c*b));
    x=max(x,a*(b+c));
    //x=max(x,(b*c)+a);
    //x=max(x,(a*c)+b);
    cout<<x;
    return 0;
}
