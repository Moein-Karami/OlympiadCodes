#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long int n;
    cin>>n;
    long long int a[n];
    long long int cnt=0,sum=0;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
    {
        if(a[i]!=a[i-1])
        {
            cnt+=fabs(a[i]-sum);
            sum+=(a[i]-sum);
        }
        //cout<<sum<<" ";
    }
    //cout<<endl;
    cout<<cnt;
    return 0;
}
