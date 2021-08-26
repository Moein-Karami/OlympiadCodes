#include <iostream>

using namespace std;

int main()
{
    long long int n;
    cin>>n;
    long long int cnt=1,i=1;
    while(i<n)
    {
        cnt++;
        i+=cnt;
    }
    if(i==n)
        cout<<cnt;
    else
    {
        cout<<n-i+cnt;
    }
    return 0;
}
