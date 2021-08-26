#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin>>t;
    string s="South",e="East",n="North",w="West";
    int m;
    string d;
    int o=0,a=0;
    for(int i=1;i<=t;i++)
    {
        cin>>m>>d;
        if(a==0&&d!=s)
        {
            cout<<"NO";
            return 0;
        }
        if(a==20000&&d!=n)
        {
            cout<<"NO";
            return 0;
        }
        if(m>20000&&d==s)
        {
            cout<<"NO";
            return 0;
        }
        if(m>20000&&d==n)
        {
            cout<<"NO";
            return 0;
        }
        if(d==s&&a+m>20000)
        {
            cout<<"NO";
            return 0;
        }
        if(d==n&&a-m<0)
        {
            cout<<"NO";
            return 0;
        }
        if(d==n)
            a=fabs(a-m);
        if(d==s)
            a+=m;
    }
    if(a!=0)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES";
    return 0;
}
