///DARK PROGRAMMER



#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    string t;
    cin>>s;
    int n=s.size();
    bool c=1;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0'&&c)
        {
            c=0;
        }
        else t.push_back(s[i]);
    }
    if(c)
    {
        for(int i=1;i<n;i++)
            cout<<t[i];
    }
    else
        cout<<t;
    return 0;
}
