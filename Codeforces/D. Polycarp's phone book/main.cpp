///Chefer


#include <bits/stdc++.h>

using namespace std;
map <string,int> mp;
string s[70010];
main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>s[i];
    set <string> t;
    string tmp;
    set<string>::iterator x;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<9;j++)
        {
            for(int k=j;k<9;k++)
            {
                tmp.clear();
                for(int l=j;l<=k;l++)
                    tmp.push_back(s[i][l]);
                t.insert(tmp);
            }
        }
        while(t.size())
        {
            x=t.begin();
            mp[*x]++;
            t.erase(*x);
        }
    }
    for(int i=1;i<=n;i++)
    {
        string ans="11111111111";
        for(int j=0;j<9;j++)
        {
            for(int k=j;k<9;k++)
            {
                tmp.clear();
                for(int l=j;l<=k;l++)
                    tmp.push_back(s[i][l]);
                if(mp[tmp]==1&&tmp.size()<ans.size())
                    ans=tmp;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
