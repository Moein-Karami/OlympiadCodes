#include <iostream>
#include <algorithm>
using namespace std;
int a[110];
int main()
{
    int n,d,m;
    cin>>n>>d;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>m;
    sort(a,a+n);
    int ans=0;
    for(int i=0;i<m;i++)
    {
        //cout<<"<<"<<i<<","<<ans<<">>"<<endl;
        if(i<n)
        {
            ans+=a[i];
        }
        else
            ans=ans-d;
    }
    cout<<ans;
    return 0;
}
