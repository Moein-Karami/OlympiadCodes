#include <iostream>

using namespace std;

int main()
{
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    int x,y,z,w;
    x=n*a;
    if(n%m!=0)
        y=(n/m+1)*b;
    else
        y=b*(n/m);
    if(n%m!=0)
        z=(n/m)*b+(n%m)*a;
    else
        z=(((n-m)/m)*b)+m*a;
    w=min(x,y);
    w=min(w,z);
    cout<<w;
    return 0;
}
