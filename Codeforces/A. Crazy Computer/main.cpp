#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int a[n];
    int cnt=1;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)
    {
        if(a[i]-a[i-1]<=m)
            cnt++;
        else
            cnt=1;
    }
    cout<<cnt;
    return 0;
}
