#include <iostream>
#define f first
#define s second
using namespace std;
pair <int,int> a[1000000];
int n,ans;
int p(int j)
{
    for(int i=j;i<=n;i++)
    {cout<<4<<endl;
        if(ans>=1900&&a[i].s==2)
        {
            cout<<"Impossible";
            return n+4;
        }

        if(ans<=1899&&a[i].s==1)
        {

            cout<<"Impossible";
            return n+4;
        }
        ans+=a[i].f;
    }
    cout<<ans;
    return n+4;
}
int main()
{

    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].f>>a[i].s;
    bool b=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i].s!=a[i-1].s)
            b=0;
    }
    if(b)
    {
        if(a[1].s==1)
            cout<<"Infinity";
        else
            cout<<1899;
    }
    for(int i=2;i<=n;i++)
    {
        if(a[i].s>a[i-1].s)
        {
            if(a[i-1].f>=0)
            {
                cout<<"Impossible";
                return 0;
            }
            else
            {
                ans=1899;
                i=p(i);
            }
        }
        else
        {

        }
    }

    return 0;
}
