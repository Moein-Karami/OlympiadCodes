///Chefer


#include <bits/stdc++.h>

using namespace std;
stack <int> p;
main()
{
    string s;
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(s[i]=='<')
        {
            if(s[i+1]=='/')
            {
                p.pop();
                while(s[i]!='>')
                    i++;
            }
            else
            {
                if(s[i+1]=='U')
                    p.push(1);
                else
                    p.push(0);
                while(s[i]!='>')
                    i++;
            }
        }
        else
        {
            if(p.size())
            {
                bool c=p.top();
                if(c)
                {
                    if(s[i]>'Z')
                        s[i]-='a'-'A';
                }
                else
                    if(s[i]<'a')
                        s[i]+='a'-'A';
            }
            cout<<s[i];
        }
    }
    return 0;
}
