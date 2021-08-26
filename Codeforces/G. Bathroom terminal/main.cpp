///Chefer


#include <bits/stdc++.h>

using namespace std;
const int maxn=2e5;
string s[maxn];
map <string,int> mp;
string tmp;
string a;
int solve(int t,int siz)
{
    if(!t)
    {
        string check;
        int cnt=0;
        for(int i=0;i<siz;i++)
        {
            while(tmp[i]=='?'&&i<siz)
            {
                if(a[cnt]!='f')
                    check.push_back(a[cnt]);
                cnt++;
                i++;
            }
            if(i<siz)
                check.push_back(tmp[i]);
        }
        //cerr<<check<<endl;
        return mp[check];
    }
    int ret=0;
    for(char i='a';i<='f';i++)
    {
        a.push_back(i);
        ret+=solve(t-1,siz);
        a.pop_back();
    }

    return ret;
}
main()
{
    int n,m;
    cin>>n>>m;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        //cnt++;
        mp[s[i]]++;
        //cnt++;
    }
    for(int i=0;i<m;i++)
    {
        cin>>tmp;
        int t=0;
        for(int j=0;j<tmp.size();j++)
            if(tmp[j]=='?')
                t++;
        a.clear();
        cout<<solve(t,tmp.size())<<endl;
    }

    return 0;
}
