#include <iostream>

using namespace std;

int main()
{
    long long int t,s,x;
    cin>>t>>s>>x;
    if(x>=t)
    {
    if((x-t)%s==0)
        cout<<"YES";
    else if ((x-t)%s==1)
    {
    if(x-t!=1)
    cout<<"YES";
    else
    cout<<"NO";
    }
    else
        cout<<"NO";
    }
    else
        cout<<"NO";
    return 0;
}
