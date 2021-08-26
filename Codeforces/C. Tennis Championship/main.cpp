#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long int n;
    cin>>n;
    long long int cnt=0;
    while(n>1)
    {
        if(n%2!=0)
        n++;
        cnt++;
        n/=2;
    }
    cout<<cnt;
    return 0;
}
