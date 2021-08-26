#include <iostream>
#define ll long long
using namespace std;
const int maxn=1000000;

ll int a[maxn];
ll int dpl[maxn];
ll int dpr[maxn];
ll int p[maxn];
ll int pl[maxn];
ll int pr[maxn];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n; i++)
    {
        cin>>a[i];
        p[i]=a[i]+p[i-1];
    }
    if(p[n-1]%3!=0)
    {
        cout<<0;
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        if(p[i]==p[n-1]/3)
            dpl[i]++;
        ///
        //cout<<dpl[i]<<" ";
        ///
    }
    ///
    //cout<<endl;
    ///

    for(int i=n-1;i>=0;i--)
    {
        if(p[n-1]-p[i-1]==p[n-1]/3)
        {
            dpr[i]++;
        }
    }

    ///
    //for(int i=0;i<n;i++)
    //{
      //  cout<<dpr[i]<<" ";
    //}
    ///
    //cout<<endl;
    ///

    for(int i=0;i<n;i++)
    {
        pl[i]=pl[i-1]+dpl[i];
        pr[i]=pr[i-1]+dpr[i];
    }
    ///
    //for(int i=0;i<n;i++)
    //{
        //cout<<pl[i]<<" ";
    //}
    ///
    //cout<<endl;
    ///

    ///
    //for(int i=0;i<n;i++)
    //{
        //cout<<pr[i]<<" ";
    //}
    ///
    //cout<<endl;
    ///


    long long int ans=0;
    for(int i=0;i<n;i++)
    {
        if(dpl[i]==1)
        {
            if(i+1<=n-1)
            ans+=(pr[n-1]-pr[i+1]);
        }
    }
    cout<<ans;
    return 0;
}
