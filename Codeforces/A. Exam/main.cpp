#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<1<<endl<<1;
        return 0;
    }
    if(n==2)
    {
        cout<<1<<endl<<1;
        return 0;
    }
    if(n==3)
    {
        cout<<2<<endl<<1<<" "<<3;
        return 0;
    }
    if(n==4)
    {
        cout<<4<<endl<<3<<" "<<1<<" "<<4<<" "<<2;
        return 0;
    }
    if(n%2==0)
    {
        int cnt=1;
        cout<<n<<endl<<n/2+1<<" ";
        for(int i=n;i>n/2;i--)
        {
            if(i==n/2+1)
            {
                cout<<cnt;
                return 0;
            }
            cout<<cnt<<" "<<i<<" ";
            cnt++;
        }
    }
    else
    {
        int cnt=1;
        cout<<n<<endl<<n/2+1<<" ";
        for(int i=n;i>n/2+1;i--)
        {
            cout<<cnt<<" "<<i<<" ";
            cnt++;
        }

    }
    return 0;
}
