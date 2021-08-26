///Chefer


#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn=1e6,inf=1e10;
int ans=0;
int a[maxn];
void solve(int l,int r,int x)
{
    if(l+1>=r)
        return ;
    int mini=inf;
    for(int i=l+1;i<r;i++)
        mini=min(mini,a[i]);
    ans+=mini-x;
    vector <int> t;
    for(int i=l+1;i<r;i++)
        if(a[i]==mini)
            t.push_back(i);
    solve(l,t[0],mini);
    for(int i=1;i<t.size();i++)
    {
        solve(t[i-1],t[i],mini);
    }
    solve(t[t.size()-1],r,mini);
}
main()
{
    int mini=inf;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mini=min(mini,a[i]);
    }
    vector <int> t;
    for(int i=1;i<=n;i++)
        if(a[i]==mini)
            t.push_back(i);
    ans=mini;
    solve(0,t[0],mini);
    for(int i=1;i<t.size();i++)
    {
        solve(t[i-1],t[i],mini);
    }
    solve(t[t.size()-1],n+1,mini);
    cout<<ans;
    return 0;
}
