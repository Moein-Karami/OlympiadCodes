#include <iostream>
using namespace std;

int main()
{
    int n,cnt=0,tmp,mini=1e9,maxi=0;
    cin>>n;
    int a[n],x,y;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>maxi)
            maxi=a[i];
        if(a[i]<mini)
            mini=a[i];

    }
    for(int i=0;i<n;i++)
    {
        if(a[i]==maxi)
        {
            x=i;
            i=n;
        }

    }

    for(int i=x;i>0;i--)
    {
        tmp=a[i];
        a[i]=a[i-1];
        a[i-1]=tmp;
        cnt++;

    }
    for(int i=n;i>=0;i--)
    {
        if(a[i]==mini)
        {
            y=i;
            i=-1;
        }

    }
    for(int i=y;i<n-1;i++)
    {
        tmp=a[i];
        a[i]=a[i+11];
        a[i+1]=tmp;
        cnt++;

    }
    cout<<cnt;
    return 0;
}
