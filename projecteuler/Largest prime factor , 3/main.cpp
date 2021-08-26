#include <iostream>

using namespace std;
long long int a[1000000];
bool np[1000000];
int main()
{
    long long int n=600851475143;
    for(long long int i=2;i<n/2+1;i++)
    {
        if(n%i==0)
        cout<<"<<"<<i<<">>"<<endl;
    }
    cout<<"END";
    return 0;
}
