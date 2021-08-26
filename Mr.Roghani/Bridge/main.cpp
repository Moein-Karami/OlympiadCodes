/// I'm Chefer ;)


#include <bits/stdc++.h>

using namespace std;
int dp[1000000];
int n;
int a[19];
vector <int> v;
int solve(int x)
{
    v.clear();
    for(int i=0;i<n;i++)
        if(x&(1<<i))
            v.push_back(i);
    int mini=1e9;
    int t1=0,t2=0;
    for(int i=0;i<(1<<(v.size()));i++)
    {
        t1=0;
        t2=0;
        for(int j=0;j<(1<<(v.size()));j++)
        {
            if(i&(1<<j))
                t1+=(1<<v[j]);
            else
                t2+=(1<<v[j]);
        }
        mini=min(mini,solve(t1)+solve(t2));
    }
    return mini;
}
int main()
{
    cin>>n;
    for(int i=0;i<=n;i++)
        cin>>a[i];
    int cnt=1;
    for(int i=1;i<(1<<n);i*=2)
        {
            dp[i]=a[cnt];
            cnt++;
        }
    cout<<solve((1<<n)-1);
    return 0;
}
