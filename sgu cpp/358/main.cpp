#include <iostream>

using namespace std;

void s(int[],int);

int main()
{
    int x=3;

    int a[x],b[x],c[x],d[x];

    for(int i=0 ; i<x;i++)
    {
        cin>>a[i];
        if(a[i]<-1000||a[i]>1000)
            return 0 ;
    }
    for(int i=0 ; i<x;i++)
    {
        cin>>b[i];
        if(b[i]<-1000||b[i]>1000)
            return 0 ;
    }
    for(int i=0 ; i<x;i++)
    {
       cin>>c[i];
       if(c[i]<-1000||c[i]>1000)
            return 0 ;
    }

    s(a , x);
    s(a , x);
    s(b , x);
    s(b , x);
    s(c , x);
    s(c , x);

    d[1]=a[0];
    d[1]=b[1];
    d[2]=c[1];

    s(d,x);
    s(d,x);

    cout<<d[1];

    return 0 ;
}

void s(int q[] , int x)
{
    int z=0;
    for(int i=1;i<x;i++)
    {
        if(q[i]<q [i-1])
        {
            z=q[i];
            q[i]=q[i-1];
            q[i-1]=z;
        }
    }
}
