#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=10357;
const int n=7;
int ans;
vector <int> v;
int fact[10];
int a[n+1],b[n+1],jad[n+1][n+1];
void build(int x,int y,int ans)
{
    if(x==n+1)
    {
        v.push_back(ans);
        return;
    }
    for(int i=y;i<n+1;i++)
        build(x+1,i,ans*10+i);

}

bool check(int x,int y)
{
    int q=x,w=y,k=0,l=0;
    for(int i=n;i>=1;i--)
    {
        a[i]=x%10;
        b[i]=y%10;
        k+=a[i];
        l+=b[i];
        x/=10;
        y/=10;
        for(int j=1;j<=n;j++)
            jad[i][j]=0;
    }
    if(l!=k)
        return 0;
    for(int i=1;i<=n;i++)
    {
        sort(a,a+n+1);
        for(int j=n;j>n-b[i];j--)
            a[j]--;
        for(int j=1;j<=n;j++)
        {
            if(a[j]<0)
            {
                return 0;
            }
        }
    }
    for(int j=0;j<=n;j++)
    {
        if(a[j]>0)
        {
            return 0;
        }
    }
    return 1;
}
int f(int x)
{
    int ret=fact[n];
    int c[10];
    for(int i=0;i<10;i++)
        c[i]=0;
    for(int i=1;i<=n;i++)
    {
        c[x%10]++;
        x/=10;
    }
    for(int i=0;i<10;i++)
        ret/=fact[c[i]];
    return ret;
}
main()
{
    fact[0]=1;
    for(int i=1;i<10;i++)
        fact[i]=fact[i-1]*i;

    for(int i=0;i<=n;i++)
        build(2,i,i);
    int s=v.size();
    for(int i=0;i<s;i++)
    {
        for(int j=0;j<s;j++)
        {
            if(check(v[i],v[j]))
                ans=(ans+f(v[i])*f(v[j]))%mod;
        }
    }
    cout<<ans%mod;
    return 0;
}
