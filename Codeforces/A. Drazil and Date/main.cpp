#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a,b,s;
    cin>>a>>b>>s;
    a=fabs(a);
    b=fabs(b);
    if(a+b==s)
        cout<<"YES";
    else if((s-a-b)%2==0&&s-a-b>=0)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
