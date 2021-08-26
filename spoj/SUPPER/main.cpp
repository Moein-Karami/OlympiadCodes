///Chefer


#include <bits/stdc++.h>

using namespace std;
const int maxn=2e5,inf=1e9;
int dpl[maxn],dpr[maxn],ansl[maxn],ansr[maxn];
int a[maxn];
int n;
int binaryl(int x)
{
    int l=0,r=n,mid;
    while(l+1!=r)
    {
        mid=(l+r)/2;
        if(dpl[mid]<=x)
            l=mid;
        else
            r=mid;
    }
    return l;
}
int binaryr(int x)
{
    int l=0,r=n,mid;
    while(l+1!=r)
    {
        mid=(l+r)/2;
        if(x<=dpr[mid])
            l=mid;
        else
            r=mid;
    }
    return l;
}
main()
{
    ios_base::sync_with_stdio(false);
    for(int o=1;o<=10;o++)
    {
        int maxi=0;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
            dpl[i]=inf,dpr[i]=0;
        dpr[0]=inf;
        for(int i=1;i<=n;i++)
        {
            int t=binaryl(a[i]);
            ansl[a[i]]=t+1;
            maxi=max(maxi,ansl[a[i]]);
            dpl[t+1]=min(dpl[t+1],a[i]);
        }
        for(int i=n;i>=0;i--)
        {
            int t=binaryr(a[i]);
            ansr[a[i]]=t+1;
            dpr[t+1]=max(dpr[t+1],a[i]);
        }
        maxi++;
        int ans=0;
        for(int i=1;i<=n;i++)
            if(ansl[i]+ansr[i]==maxi)
                ans++;
        cout<<ans<<endl;
        for(int i=1;i<=n;i++)
            if(ansl[i]+ansr[i]==maxi)
                cout<<i<<" ";
        cout<<endl;
    }

    return 0;
}
