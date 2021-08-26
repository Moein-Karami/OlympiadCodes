///DARK PROGRAMMER


#include <iostream>

using namespace std;

int main()
{
    long long int x,y;
    cin>>x>>y;
    long long int a=0;
    for(long long int i=x-1;i>=0;i--)
    {
        long long int m;
        cin>>m;
        long long int q=1;
        for(long long int j=1;j<=i;j++)
            q*=y;
        q*=m;
        a+=q;
    }
    cin>>x>>y;
    long long int b=0;
    for(long long int i=x-1;i>=0;i--)
    {
        long long int m;
        cin>>m;
        long long int q=1;
        for(long long int j=1;j<=i;j++)
            q*=y;
        q*=m;
        b+=q;
    }
    if(a==b)
        cout<<"=";
    if(a>b)
        cout<<">";
    if(a<b)
        cout<<"<";
    return 0;
}
