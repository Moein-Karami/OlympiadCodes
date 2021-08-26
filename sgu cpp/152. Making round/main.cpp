///Chefer


#include <bits/stdc++.h>

using namespace std;
const int maxn=1e4+4;
int a[maxn],ans[maxn];
bool b[maxn];
main()
{
    int n;
    int s=0;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],s+=a[i];
    int t=0;
    int ts=0;
    for(int i=1;i<=n;i++)
    {
        if((a[i]*100)%s!=0)
        {
            t++;
            b[i]=1;
        }
        ans[i]=(a[i]*100)/s;
        ts+=ans[i];
    }
    ts=100-ts;
    for(int i=1;i<=n;i++)
    {
        if(b[i]&&ts)
        {
            ans[i]++;
            ts--;
        }
        cout<<ans[i]<<" ";
    }
    return 0;
}
