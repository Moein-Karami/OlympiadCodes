#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=10631;
int h[200000];
int solve(int l,int r)
{
    if(l>r)
        return 0;
    int x=h[l];
    bool b=1;
    for(int i=l;i<=r;i++)
    {
        if(x!=h[i])
        {
            b=0;
            break;
        }
    }
    if(b)
        return 1;
    vector <int> v;
    int maxi=0;
    for(int i=l;i<=r;i++)
    {
        if(h[i]>h[maxi])
        {
            v.clear();
            maxi=i;
            v.push_back(maxi);
        }
        else if(h[i]==h[maxi])
            v.push_back(i);
    }
    int ret=(1+solve(l,v[0]-1))%mod;
    for(int i=1;i<v.size();i++)
    {
        ret=(ret+solve(v[i-1]+1,v[i]-1))%mod;
    }
    ret=(ret+solve(v[v.size()-1]+1,r))%mod;
        return ret;
}
main()
{
    int x=20000;
    cin>>x;
    h[1]=123;
    h[2]=456;
    for(int i=3;i<=x;i++)
        h[i]=((h[i-1]+h[i-2])%1234)+1;
    int maxi=0;
    vector <int> v;
    for(int i=1;i<=x;i++)
    {
        if(h[i]>h[maxi])
        {
            v.clear();
            maxi=i;
            v.push_back(maxi);
        }
        else if(h[i]==h[maxi])
            v.push_back(i);
    }

    int ans=1+solve(1,v[0]-1);
    for(int i=1;i<v.size();i++)
    {
        ans=(ans+solve(v[i-1]+1,v[i]-1))%mod;
    }
    ans=(ans+solve(v[v.size()-1]+1,x))%mod;
    int ret=1;
    cout<<ans<<endl;
    for(int i=1;i<=4;i++)
        ret=(ret*ans)%mod;
    cout<<ret;
    return 0;
}
