#include <iostream>

using namespace std;

int main()
{
    int n,k1=0,k2=0;
    cin>>n;
    int a[n+1];
    a[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]%2==0)
            k2++;
        else
            k1++;
    }
    if(k2>k1)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]%2==1)
            {
                cout<<i;
                return 0;
            }
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]%2==0)
            {
                cout<<i;
                return 0;
            }
        }
    }
    return 0;
}
