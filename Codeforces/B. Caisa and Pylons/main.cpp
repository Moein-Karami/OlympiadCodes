#include <iostream>

using namespace std;
int h[1000000];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>h[i];
    int ans=0,en=0;
    for(int i=0;i<n;i++)
    {
        if(en+h[i]-h[i+1]<0)
        {

            int a=(en+h[i]-h[i+1]);
            en=0;
            ans+=-a;
        }
        else
            en+=h[i]-h[i+1];
    }
    cout<<ans;
    return 0;
}
