///DARK PROGRAMMER


#include <iostream>

using namespace std;

int main()
{
    int n,a;
    bool b=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        if(a==1)
        {
           b=1 ;
           break;
        }

    }
    if(b)
        cout<<-1;
    else
        cout<<1;
    return 0;
}
