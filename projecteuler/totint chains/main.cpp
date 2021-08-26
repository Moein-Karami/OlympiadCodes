#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[40000001];
const int maxn=40000000;
int fi[maxn+10];
int dp[maxn+10];
int ans;
main()
{
    for(int i=2;i<=maxn;i++)
    {
        if(!a[i])
        {
            for(int j=i;j<=maxn;j+=i)
                a[j]=i;
        }
    }
    fi[1]=1;
    for(int i=2;i<=maxn;i++)
    {
        vector <int> v;
        v.push_back(a[i]);
        int x=i;
        while(x>1)
        {
            if(a[x]!=v[v.size()-1])
                v.push_back(a[x]);
            x/=a[x];
        }
        int t=1;
        int tmp=1;
        for(int j=0;j<v.size();j++)
            t*=(v[j]-1),tmp*=v[j];
        fi[i]=t*(i/tmp);
    }
    dp[1]=1;
    for(int i=2;i<=maxn;i++)
    {
        dp[i]=dp[fi[i]]+1;
        if(i==a[i]&&dp[i]==25)
            ans+=i;
    }
    cout<<ans;
    return 0;
}
