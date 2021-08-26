#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    if(m==1||n==1)
        cout<<"Akshat";
    else
    {
        if(n%2==1&&m>n)
            cout<<"Akshat";
        else if(m%2==1&&n>m)
            cout<<"Akshat";
        else
        {
            if((m*n)%2==0)
                cout<<"Malvika";
            else
                cout<<"Akshat";
        }
    }


    return 0;
}
