///Chefer


#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
int inf=1e9;
typedef pair<int,int> pii;
vector <pii> v[700];
int a[700];
int dp[700][700];
int s[700][700];
pii p[700][700];
main()
{
    for(int i=1;i<=600;i++)
        for(int j=1;j<=600;j++)
            dp[i][j]=inf;
    int n,k,poo;
    cin>>n>>k>>poo;
    for(int i=1;i<=k;i++)
        cin>>a[i],v[i].push_back(pii(0,0));
    for(int i=1;i<=n;i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        v[t2].push_back(pii(t1,i));
    }
    for(int i=1;i<=k;i++)
        sort(v[i].begin(),v[i].end());
    for(int i=1;i<=k;i++)
        for(int j=1;j<v[i].size();j++)
            s[i][j]=s[i][j-1]+v[i][j].f;
    for(int i=1;i<v[1].size();i++)
        dp[1][i]=a[1]+s[1][i];
    for(int i=2;i<=k;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int mini=dp[i-1][j];
            p[i][j]=pii(j,0);
            int t=v[i].size();
            t=min(t,j+1);
            for(int l=1;l<t;l++)
            {
                if(mini>s[i][l]+a[i]+dp[i-1][j-l])
                    p[i][j]=pii(j-l,l);
                mini=min(mini,s[i][l]+a[i]+dp[i-1][j-l]);
            }

            dp[i][j]=mini;
        }
    }
    pii ans;
    for(int i=n;i>=0;i--)
    {
        if(dp[k][i]<=poo)
        {
            cout<<i<<endl;
            ans.f=p[k][i].f;
            ans.s=p[k][i].s;
            break;
        }
    }
    while(k)
    {
        for(int i=1;i<=ans.s;i++)
            cout<<v[k][i].s<<" ";
        k--;
        if(k==1)
            for(int i=1;i<=ans.f;i++)
                cout<<v[k][i].s<<" ";
        ans.f=p[k][ans.f].f;
        ans.s=p[k][ans.f].s;

    }
    return 0;
}
