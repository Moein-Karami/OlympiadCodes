///Chefer


#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
const int maxn=3e4,inf =1e9;
pii a[maxn];
int t[maxn];
int dp[maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    int q;
    cin>>q;
    for(int o=1;o<=q;o++)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i].f>>a[i].s,a[i].f*=-1;
        sort(a,a+n);
        for(int i=0;i<n;i++)
            t[i]=a[i].s;
        for(int i=1;i<n+10;i++)
            dp[i]=inf;
        for(int i=0;i<n;i++)
        {
            int l=0,r=n+1;
            while(l+1!=r)
            {
                int mid=(l+r)/2;
                if(dp[mid]<=t[i])
                    l=mid;
                else
                    r=mid;
            }
            dp[l+1]=min(dp[l+1],t[i]);
        }
        for(int i=n;i>=0;i--)
        {
            if(dp[i]!=inf)
            {
                cout<<i<<endl;
                break;
            }
        }


    }
    return 0;
}
