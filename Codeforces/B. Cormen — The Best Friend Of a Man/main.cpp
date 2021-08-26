#include <iostream>

using namespace std;
int a[1000];
int main()
{
    int n,k,cnt=0;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)
    {
        if(k>=a[i]+a[i-1])
        {
            cnt+=k-(a[i]+a[i-1]);
            a[i]+=k-(a[i]+a[i-1]);
        }
    }
    cout<<cnt<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
