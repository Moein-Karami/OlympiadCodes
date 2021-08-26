#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        int h,m;
        cin>>h>>m;
        a[i]=60*h+m;
    }
    int cnt=1,a1=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]==a[i-1])
            cnt++;
        else
            cnt=1;
        if(a1<cnt)
            a1=cnt;

    }
    if(n!=1)
    cout<<a1;
    else
        cout<<1;
    return 0;
}
