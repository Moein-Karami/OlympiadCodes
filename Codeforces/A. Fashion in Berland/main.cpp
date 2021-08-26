#include <iostream>

using namespace std;
int a[10000];
int cnt;
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]==0)
            cnt++;
    }
    if(n>1)
    {
    if(cnt==1)
        cout<<"YES";
    else
        cout<<"NO";
    }
    else
    {
        if(a[0]==1)
         cout<<"YES";
    else
        cout<<"NO";

    }
    return 0;
}
