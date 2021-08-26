#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=10009;
string s[20];
bool b[1000000000];
int cnt;
char sar[]={'1','0','0','0','0','1','0','0','0'};
int tavan(int x)
{
    for(int i=60;i>=0;i--)
        if(x>=(1LL<<i))
            return i;
}
main()
{

    int mini=1e18;
    vector <int> v;
    for(int i=1;i<=14;i++)
        if(i!=8&&i!=1&&i!=3&&i!=7)
            v.push_back(i);
    for(int i=0;i<v.size();i++)
    {
        for(int j=tavan(v[i]);j>=0;j--)
        {
            if(v[i]&(1<<j))
                s[v[i]].push_back('1');
            else
                s[v[i]].push_back('0');
        }
    }

    do
    {
        string t;
        for(int i=0;i<9;i++)
            t.push_back(sar[i]);
        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<s[v[i]].size();j++)
                t.push_back(s[v[i]][j]);
        }
        for(int i=0;i<10;i++)
            t.push_back('1');
        int ans=0;
        for(int i=0;i<t.size();i++)
        {
            if(t[i]=='1')
                ans+=(1LL<<(t.size()-i-1LL));
        }
        if(ans==mini)
            cnt++;
        else if(ans<mini)
            cnt=1;
        mini=min(ans,mini);
                                                                                                                                                                                        mini=(min(ans,mini));
    }while(next_permutation(v.begin(),v.end()));
    cout<<cnt<<endl;
    cnt%=mod;
    cnt*=24;
    cout<<mini<<" "<<cnt<<endl<<((mini%mod)*cnt)%mod;
    return 0;
}
