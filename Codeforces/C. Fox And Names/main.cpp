///Chefer



#include <bits/stdc++.h>

using namespace std;
string s[110];
int n;
map <char,int> mp1;
map <int,char>mp2;
vector <int> v[110],ans;
int tmp[110];
queue <int> q;
int siz[110];
main()
{
    int l;
    mp1['0']=0;
    mp2[0]='0';
    int cnt=1;
    for(char i='a';i<='z';i++)
    {
        mp1[i]=cnt;
        mp2[cnt]=i;
        cnt++;
    }
    int maxi=0;
    cin>>n;
    if(n==1)
    {
        for(char i='a';i<='z';i++)
        {
            cout<<i;
        }
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        siz[i]=s[i].size();
        if(s[i].size()>maxi)
            maxi=s[i].size();
    }
    for(int i=1;i<=n;i++)
    {
        while(s[i].size()<=maxi)
            s[i].push_back('0');
    }
    for(int i=1;i<n;i++)
    {
        if(siz[i]>siz[i+1])
        {
            bool c=1;
            for(int j=0;j<siz[i+1];j++)
                if(s[i][j]!=s[i+1][j])
                    c=0;
            if(c)
            {
                cout<<"Impossible";
                return 0;
            }
        }
        cnt=0;
        while(s[i][cnt]==s[i+1][cnt])
                cnt++;
        tmp[mp1[s[i][cnt]]]++;
        v[mp1[s[i+1][cnt]]].push_back(mp1[s[i][cnt]]);
    }
    for(int i=0;i<27;i++)
    {
        if(tmp[i]==0)
            q.push(i);
    }
    while(q.size())
    {
        int x=q.front();
        ans.push_back(x);
        q.pop();
        for(int i=0;i<v[x].size();i++)
        {
            tmp[v[x][i]]--;
            if(tmp[v[x][i]]==0)
                q.push(v[x][i]);
        }
    }
    if(ans.size()!=27)
    {
        cout<<"Impossible";
        return 0;
    }
    for(int i=26;i>=0;i--)
        if(mp2[ans[i]]!='0')
            cout<<mp2[ans[i]];
    return 0 ;
}
