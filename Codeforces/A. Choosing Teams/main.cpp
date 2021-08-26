#include <iostream>
#include <algorithm>
using namespace std;
int a[100000];
int main()
{
    int k,n;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int cnt=0;
    a[n]=1e9;
    a[n+1]=1e9;
    a[n+2]=1e9;
    for(int i=0;i<n;i++)
    {
        if(a[i]+k<=5&&a[i+1]+k<=5&&a[i+2]+k<=5)
        {
            cnt++;
            i+=2;
        }
    }
    cout<<cnt;
    return 0;
}
