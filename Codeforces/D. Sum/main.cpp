#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6;
int a[maxn],dp[maxn];
char ans[maxn],t[maxn];
main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dp[n]=a[n];
    ans[n]='+';
    for(int i=n-1;i>0;i--)
    {
        if(dp[i+1]>=a[i])
        {
            ans[i]='-';
            dp[i]=dp[i+1]-a[i];
        }
        else
        {
            ans[i]='+';
            t[i+1]='-';
            dp[i]=a[i]-dp[i+1];
        }
    }
    bool b=0;
    for(int i=1;i<=n;i++)
    {
        if(t[i]=='-')
            b=1-b;
        if(!b)
            cout<<ans[i];
        else
        {
            if(ans[i]=='-')
                cout<<"+";
            else
                cout<<"-";
        }
    }
    return 0;
}
