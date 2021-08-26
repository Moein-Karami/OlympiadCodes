#include <iostream>

using namespace std;

int main()
{
    int h , m ;
    cin>>h>>m;
    if(h!=0)
    h=12-h;
    if(m!=0)
    m=60-m;
    if(h<10&&m<10)
    {
        cout<<0<<h<<":"<<0<<m;
    }
    else if(h<10)
    {
       cout<<0<<h<<":"<<m;
    }
    else if(m<10)
    {
        cout<<h<<":"<<0<<m;
    }
    else
    {
        cout<<h<<":"<<m;
    }
    return 0;
}
