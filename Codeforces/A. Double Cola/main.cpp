#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int cnt=1;
    int m=5;
    while(n>=m)
    {
        cnt*=2;
        n=n-m;
        m*=2;
    }
    int x=n/cnt;
    //cout<<x<<" , "<<cnt<<","<<m;
    if(n%cnt==0)
    {
            if(x==1&&n%cnt==0)
        {
            cout<< "Sheldon";
        }
        if(x==2&&n%cnt==0)
        {
            cout<< "Leonard";
        }
        if(x==3&&n%cnt==0)
        {
            cout<< "Penny";
        }
        if(x==4&&n%cnt==0)
        {
            cout<< "Rajesh";
        }
        if(x==0&&n%cnt==0)
        {
            cout<<"Howard";
        }
    }
    else
    {
        if(x==0)
        {
            cout<< "Sheldon";
        }
        if(x==1)
        {
            cout<< "Leonard";
        }
        if(x==2)
        {
            cout<< "Penny";
        }
        if(x==3)
        {
            cout<< "Rajesh";
        }
        if(x==4)
        {
            cout<<"Howard";
        }
    }

    return 0;
}
