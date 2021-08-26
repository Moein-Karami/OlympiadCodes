#include <iostream>

using namespace std;
long long int a[100000];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int cnt=1,maxi=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]>a[i-1])
            cnt++;
        if (a[i]<=a[i-1]||i==n-1)
        {
            if(cnt>maxi)
                maxi=cnt;
            cnt=1;
        }
    }
    if(n!=1)
    cout<<maxi;
    else
        cout<<1;
    return 0;
}
