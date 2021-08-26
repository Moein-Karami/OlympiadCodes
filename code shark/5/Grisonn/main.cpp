#include <bits/stdc++.h>
#define int long long int
using namespace std;
int p,q;
int mod=11161;
map<int,string> mp[4];
string solve(int x,int y)
{
    //cerr<<"X Y : "<<x<<" "<<y<<endl;
    if(x==1)
        return "";
    if(x<1)
        return "FUCK";
    if(mp[y][x]!="")
        return mp[y][x];
    string ret="FUCK";
    if(y==1)
    {
        string t1=solve(x-p,2),t2=solve(x-q,2);
        string s1="FUCK",s2="FUCK";
        if(t1!="FUCK")
            s1="1"+t1;
        if(t2!="FUCK")
            s2="2"+t2;
        if(s1!="FUCK")
            ret=s1;
        if(s2!="FUCK")
            ret=min(ret,s2);
    }
    else
    {
        string t1="FUCK",t2="FUCK";
        if(x%q==0)
            t2=solve(x/q,1);
        if(x%p==0)
            t1=solve(x/p,1);
        string s1="FUCK",s2="FUCK";
        if(t1!="FUCK")
            s1="1"+t1;
        if(t2!="FUCK")
            s2="2"+t2;
        if(s1!="FUCK")
            ret=s1;
        if(s2!="FUCK")
            ret=min(ret,s2);
    }
    mp[y][x]=ret;
    return ret;
}
main()
{
    int n;
    cin>>n>>q>>p;
    string s;
    //for(int i=2;i<=n;i++)
    //{
    string s1=solve(n,1),s2=solve(n,2);
    string t1="FUCK",t2=t1;
    if(s1!="FUCK")
        t1="1"+s1;
    if(s2!="FUCk")
        t2="2"+s2;
    if(t1!="FUCK")
        s=t1;
    if(t2!="FUCK")
        s=min(s,t2);
    //}
    int ans=0;
    for(int i=0;i<s.size();i++)
        ans=(10*ans+s[i]-'0')%mod;
    cout<<ans;
    return 0;
}
