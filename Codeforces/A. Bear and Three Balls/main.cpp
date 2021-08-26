#include <iostream>
#include <algorithm>
using namespace std;
int a[1000];
int main()
{
    int n,i,cnt=0;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(i=1;i<n;i++)
    {
        if(a[i]==a[i-1])
        {
            a[i-1]=-1;
            cnt++;
        }
    }
    sort(a,a+n);

    for(i=cnt;i<n-2;i++)
    {
        if(a[i]==a[i+1]-1&&a[i]==a[i+2]-2)
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}
