#include <iostream>

using namespace std;

int main()
{
    long long int n;
    cin>>n;
    long long int mini=1e9;
    long long int x,sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        sum+=x;
        if(x%2!=0&&x<mini)
            mini=x;
    }
    if(sum%2==0)
        cout<<sum;
    else
        cout<<sum-mini;
    return 0;
}
