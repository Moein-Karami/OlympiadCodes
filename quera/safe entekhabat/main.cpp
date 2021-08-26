#include <iostream>

using namespace std;

int main()
{
    int n;
    bool b;
    char c,w,e,r;
    cin>>n;
    b=0;
    for(int i=1;i<=n;i++)
    {
        cin>>c;
        if(c=='C')
        {
            cin>>w>>e>>r;
            b=1-b;
            continue ;
        }
        if(b)
        {
            c-=32;
            cout<<c;
        }
        else
            cout<<c;
    }
    return 0;
}
