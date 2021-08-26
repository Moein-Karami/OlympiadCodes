#include <iostream>
#include <string>
using namespace std;
string a ;
int main()
{
    int n,k;
    cin>>n>>k;
    int t,g;
    cin>>a;
    for(int i=0;i<n;i++)
    {
        if(a[i]=='G')
            g=i;
        if(a[i]=='T')
            t=i;
    }
    if(g>t)
    {
        for(int i=g;i>=t;i-=k)
        {
            if(a[i]=='#')
            {
                cout<<"NO";
                return 0;
            }
            if(a[i]=='T')
            {
                cout<<"YES";
                return 0;
            }
        }
        cout<<"NO";
            return 0;
    }
    if(t>g)
    {
        for(int i=g;i<=t;i+=k)
        {
            if(a[i]=='#')
            {
                cout<<"NO";
                return 0;
            }
            if(a[i]=='T')
            {
                cout<<"YES";
                return 0;
            }
        }
        cout<<"NO";
            return 0;
    }
    return 0;
}
