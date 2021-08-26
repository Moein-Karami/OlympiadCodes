///Chefer


#include <bits/stdc++.h>

using namespace std;
map <char,int> mp;
bool b[30];
main()
{
    int cnt=1;
    for(char i='a';i<='z';i++)
    {
        mp[i]=cnt;
        cnt++;
    }
    int tmp=0;
    string s;
    cin>>s;
    int x=s.size();
    int n;
    cin>>n;
    if(n>x)
    {
        cout<<"impossible";
        return 0;
    }
    for(int i=0;i<x;i++)
    {
        if(!b[mp[s[i]]])
        {
            tmp++;
            b[mp[s[i]]]=1;
        }
    }
    cout<<max(0,n-tmp);
    return 0;
}
