#include <iostream>

using namespace std;
int a[1000000+10];
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int cnt=0;
    bool b=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]%2==1)
            b=1;
        cnt+=a[i];
    }
    if(cnt%2==1)
    {
        cout<<"First";
        return 0;
    }
    if(!b)
    {
        cout<<"Second";
        return 0;
    }
    cout<<"First";
    return 0;
}
