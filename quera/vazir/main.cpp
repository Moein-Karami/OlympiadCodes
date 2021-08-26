#include <iostream>
#include <algorithm>
#define f first
#define s second
using namespace std;
pair <int,int> a[250000];
pair <bool,bool>b[250000];
int main()
{
    long long int n,m;
    cin>>n>>m;
    for(int i=0;i<n-1;i++)
        cin>>a[i].f>>a[i].s;
    long long int mini=1e12,maxi=0;
    for(int i=0;i<n-1;i++)
    {
        if(a[i].s<mini)
            mini=a[i].s;
        if(a[i].f>maxi)
            maxi=a[i].f;
    }
    long long int ans=mini*(m-maxi+1);
    for(int i=1;i<=mini;i++)
        b[i].f=1;
    for(int i=m;i>=maxi;i--)
        b[i].s=1;
    long long int cnt=0;
    for(int i=1;i<=m;i++)
        if(b[i].f&&b[i].s)
            cnt++;
    long long int t=cnt*(cnt-1)/2;
    cout<<ans-t;
    return 0;
}
