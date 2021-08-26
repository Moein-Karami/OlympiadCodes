#include <iostream>
#define int long long int
using namespace std;

main()
{
    int l,r;
    cin>>l>>r;
    if(r-l+1<3)
    {
        cout<<-1;
        return 0;
    }
    else if(r-l+1==3&&l%2==1)
    {
        cout<<-1;
        return 0;
    }
    else
    {
        if(l%2==0)
        {
            cout<<l<<" "<<l+1<<" "<<l+2;
        }
        else
        {
            cout<<l+1<<" "<<l+2<<" "<<l+3;
        }
    }
    return 0;
}
