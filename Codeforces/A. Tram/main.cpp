#include <iostream>

using namespace std;

int main()
{
    int x,y,n,mini=0,c=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        c=c-x+y;
        if(mini<c)
        mini=c;
    }
    cout<<mini;
    return 0;
}
