#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n%7==0)
        cout<<(n/7)*2<<" "<<(n/7)*2;
    else
    {
        if(n%7>=2)
        {

            if(n%7==6)
                cout<<(n/7)*2+1<<" ";
            else
                cout<<(n/7)*2<<" ";
            cout<<(n/7)*2+2<<" ";
        }
        else
            cout<<(n/7)*2<<" "<<(n/7)*2+1;

    }
    return 0;
}
