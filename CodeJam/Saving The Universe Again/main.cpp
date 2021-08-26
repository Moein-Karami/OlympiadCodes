#include <bits/stdc++.h>
#define int long long int
using namespace std;
string s;
int T;
int dam()
{
    int t=1;
    int ret=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='S')
            ret+=t;
        else
            t*=2;
    }
    return ret;
}
bool change()
{
    for(int i=1;i<s.size();i++)
    {
        if(s[i]=='S'&&s[i-1]=='C')
        {
            swap(s[i],s[i-1]);
            return 0;
        }
    }
    return 1;
}
vector<int> v;
main()
{
    cin>>T;
    for(int Q=1;Q<=T;Q++)
    {
        int d;
        cin>>d>>s;
        int ans=0;
        while(dam()>d)
        {
            ans++;
            if(change())
                break;
        }
        if(dam()>d)
            v.push_back(-1);
        else
            v.push_back(ans);
    }
    for(int i=0;i<v.size();i++)
    {
        cout<<"Case #"<<i+1<<": ";
        if(v[i]==-1)
            cout<<"IMPOSSIBLE"<<endl;
        else cout<<v[i]<<endl;
    }
    return 0;
}
