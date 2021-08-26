#include <bits/stdc++.h>
#define int long long int
using namespace std;
int ans;
string l , r ,t;
int tmp,cnt;
int mod=10009;
int tavan(int x)
{
    int ret=1;
    for(int i=1;i<=x;i++)
        ret*=10;
    return ret;
}
bool check ()
{
    int ch=0;
    for(int i=0;i<t.size();i++)
        for(int j=0;j<=9;j++)
            if(t[i]-'0'==j)
                ch+=(t[i]-'0')*(tavan(t.size()-i-1));
    if(ch==cnt)
        return 0;
    return 1;
}
main()
{
    cin>>t;
    cnt=1;
    for(int i=1;i<=1076;i++)
    {
        cin>>l>>t>>r;
        cnt++;
        ans+=(100*(r[9]-l[9])+10*(r[10]-l[10])+(r[11]-l[11]));
        tmp=10*(r[6]-l[6])+(r[7]-l[7]);
        tmp*=1000;
        ans+=tmp;
        tmp=10*(r[3]-l[3])+(r[4]-l[4]);
        tmp*=60000;
        ans+=tmp;
        tmp=(r[1]-l[1]);
        tmp*=3600000;
        ans+=tmp;
        ans++;
        while(check())
            cin>>t;
        cout<<ans<<endl;
    }
    cout<<endl<<ans%mod;
    return 0;
}
