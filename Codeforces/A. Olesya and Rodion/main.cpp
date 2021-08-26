#include <iostream>

using namespace std;

int main()
{
    int n,t;
    cin>>n>>t;
    if(t==10&&n!=1)
    {
        for(int i=1;i<n;i++)
            cout<<1;
        cout<<0;
    }
    if(t==10&&n==1)
        cout<<-1;
    if(t==9)
        for(int i=1;i<=n;i++)
            cout<<9;
    if(t==8)
        for(int i=1;i<=n;i++)
            cout<<8;
    if(t==7)
        for(int i=1;i<=n;i++)
            cout<<7;
    if(t==6)
        for(int i=1;i<=n;i++)
            cout<<6;
    if(t==5)
        for(int i=1;i<=n;i++)
            cout<<5;
    if(t==4)
        for(int i=1;i<=n;i++)
            cout<<4;
    if(t==3)
        for(int i=1;i<=n;i++)
            cout<<3;
    if(t==2)
        for(int i=1;i<=n;i++)
            cout<<2;
    if(t==1)
        for(int i=1;i<=n;i++)
            cout<<1;
    return 0;
}
