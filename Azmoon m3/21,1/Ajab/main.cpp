#include <bits/stdc++.h>
#define int long long int

using namespace std;
const int mod=10487;
int a[12];
int ans=1e16;
int tavan(int x,int y)
{
    int ret=1;
    for(int i=1;i<=y;i++)
        ret*=x;
    return ret;
}
void solve(vector<int> t)
{
    int ret=1;
    int s=t.size();
    for(int i=0;i<s;i++)
        ret*=(t[i]+1);
    int tmp=1;
    for(int i=0;i<s;i++)
        tmp*=tavan(a[i],t[i]);
    if(ret>=2011)
    {
        for(int i=0;i<s;i++)
            cout<<t[i]<<" ";
        cout<<": "<<tmp<<endl;
        ans=min(ans,tmp);
        return;
    }
    t.push_back(1);
    for(int i=1;i<=t[s-1];i++)
    {
        t[s]=i;
        if(ret*(i+1)>=2011)
        {
            for(int j=0;j<=s;j++)
                cout<<t[j]<<" ";
            tmp*=tavan(a[s],i);
            cout<<": "<<tmp<<endl;
            ans=min(ans,tmp);
            t.pop_back();
            return;
        }
        solve(t);
    }
    t.pop_back();
}
main()
{
    cout<<tavan(2,3)<<endl;
    a[0]=2;
    a[1]=3;
    a[2]=5;
    a[3]=7;
    a[4]=11;
    a[5]=13;
    a[6]=17;
    a[7]=19;
    a[8]=23;
    a[9]=29;
    a[10]=31;
    vector <int> t;
    t.push_back(1);
    for(int i=1;i<=20;i++)
    {
        t[0]=i;
        solve(t);
    }
    cout<<ans<<endl<<ans%mod;
    return 0;
}
