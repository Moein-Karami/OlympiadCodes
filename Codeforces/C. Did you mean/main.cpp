///Chefer


#include <bits/stdc++.h>

using namespace std;
bool a[4000];
main()
{
    string s;
    cin>>s;
    for(int i=2;i<s.size();i++)
    {
        bool b=1;
        for(int j=0;j<=2;j++)
            if(s[i-j]=='a'||s[i-j]=='e'||s[i-j]=='i'||s[i-j]=='o'||s[i-j]=='u'||(s[i]==s[i-1]&&s[i-1]==s[i-2]))
                b=0;
        if(b)
        {
            a[i]=1;
            i++;
        }
    }
    for(int i=0;i<s.size();i++)
    {
        if(a[i])
            cout<<" ";
        cout<<s[i];
    }
    return 0;
}
