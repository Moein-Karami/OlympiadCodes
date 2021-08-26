///C


#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
map<int,int> mp;
const int maxn=2e3+3;
int a[maxn];
int cnt[maxn];
int t,c;
main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(!mp[a[i]])
        {
            c++;
            mp[a[i]]=c;
        }
        a[i]=mp[a[i]];
    }
    for(int i=1;i<=n;i++)
    {
        cnt[a[i]]++;
        if(cnt[a[i]]==2)
            t++;
    }
    int ans=n;
    for(int i=n;i>=0;i--)
    {
        for(int j=i+1;j<=n+1;j++)
        {
            if(t==0)
                ans=min(ans,j-i-1);
            if(j!=n+1)
            {
                cnt[a[j]]--;
                if(cnt[a[j]]==1)
                    t--;
            }
        }
        for(int j=i+1;j<=n;j++)
        {
            cnt[a[j]]++;
            if(cnt[a[j]]==2)
                t++;
        }
    }
    cout<<ans;
}
