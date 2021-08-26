#include <iostream>

using namespace std;

int main()
{
    long long int n,a,b,c,mini;
    cin>>n>>a>>b>>c;
    int x=4-(n%4);
    if(x==4)
    {
        cout<<0;
        return 0;
    }
    if(x==1)
    {
        mini=min(a,3*c);
        mini=min(mini,b+c);
        cout<<mini;
        return 0;
    }
    if(x==2)
    {
        mini=min(2*a,b);
        mini=min(mini,2*c);
        cout<<mini;
        return 0;
    }
    if(x==3)
    {
        mini=min(3*a,c);
        mini=min(a+b,mini);
        cout<<mini;
        return 0;
    }
    return 0;
}
