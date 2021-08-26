#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n],tmp[n],cnt=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        tmp[i]=a[i];
    }

    sort(a,a+n);

    for(int i=0;i<n;i++)
    {
        if(a[i]!=tmp[i])
            cnt++;
    }
    if(cnt==2||cnt==0)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
