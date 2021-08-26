///Chefer


#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=10487;
int process(long long x)
{
    int y = 0;
    if (x % 2)
        return -1;
    for(x=x/2;x>1;x=x/2)
    {
        int b=(x+1)%2;
        y*=2;
        y+=b;
    }
  return y;
}
main()
{
    int x=mod*mod;
    string t,s;
    while(x)
    {
        if(x%2)
            t+='1';
        else
            t+='0';
        x/=2;
    }
    reverse(t.begin(),t.end());
    s+='0';
    for(int i=0;i<t.size();i++)
    {
        if(t[i]=='0')
            s+='1';
        else
            s+='0';
    }
    s+='1';
    reverse(s.begin(),s.end());
    int ans=0;
    for(int i=0;i<s.size();i++)
        ans=(ans*2+s[i]-'0');
    cout<<ans<<endl;
    int tmp=process(ans);
    cout<<tmp<<endl;
    return 0;
}
