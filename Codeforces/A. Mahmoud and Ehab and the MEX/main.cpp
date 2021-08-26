#include <iostream>

using namespace std;
int a[200];
int ans;
bool b[200];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i],b[a[i]]=1;
    int mex;
    for(int i=101;i>=0;i--)
        if(!b[i])
            mex=i;
    if(mex>k)
    {
        cout<<1<<endl;
        return 0;
    }
    if(b[k])
        ans++;
    for(int i=0;i<k;i++)
        if(!b[i])
            ans++;
    cout<<ans;
    return 0;
}
