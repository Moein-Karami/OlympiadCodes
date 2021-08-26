#include <bits/stdc++.h>

using namespace std;
vector <char> v;
int main()
{
    int n;
    cin>>n;
    string t,s;
    cin>>t;
    for(int i=0;i<t.size();i++)
    {
        bool b=1;
        for(int j=0;j<v.size();j++)
            if(v[j]==t[i])
                b=0;
        if(b)
            v.push_back(t[i]);
    }
    for(int o=1;o<=n;o++)
    {
        cin>>s;
        bool c=1;
        for(int i=0;i<s.size();i++)
        {
            bool b=0;
            for(int j=0;j<v.size();j++)
                if(v[j]==s[i])
                    b=1;
            if(!b)
            {
                c=0;
                i=s.size();
            }
        }
        if(!c)
        {
            cout<<"No"<<endl;
            continue;
        }
        for(int i=0;i<v.size();i++)
        {
            bool b=0;
            for(int j=0;j<s.size();j++)
                if(s[j]==v[i])
                    b=1;
            if(!b)
            {
                c=0;
                i=v.size();
            }
        }
        if(!c)
        {
            cout<<"No"<<endl;
            continue;
        }
        cout<<"Yes"<<endl;
    }
    return 0;
}
