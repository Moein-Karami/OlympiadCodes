#include <iostream>

using namespace std;

int main()
{
    int a[5];
    int s=0;
    for(int i=0;i<5;i++)
    {
        cin>>a[i];
        s+=a[i];
    }
    if(s%5!=0||s==0)
    {
        cout<<-1;
        return 0;
    }
    int ans=0,b=s/5,t=0,r=0,q=0;
    cout<<b;
    return 0;

}
