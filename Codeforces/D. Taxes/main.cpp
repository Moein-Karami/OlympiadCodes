#include <iostream>

using namespace std;
bool f,s;
int main()
{
    int n;
    cin>>n;
    if(n==2)
    {
        cout<<1;
        return 0;
    }
    if(n%2==0)
    {
        cout<<2;
        return 0;
    }
    else
    {
        bool b=0,c=0;
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                b=1;
                i=n;
            }
        }
        for(int i=2;i*i<=n;i++)
        {
            if((n-2)%i==0)
            {
                c=1;
                i=n;
            }
        }
        if(!b)
            cout<<1;
        else if(b&&!c)
            cout<<2;
        else
            cout<<3;
    }
    return 0;
}
