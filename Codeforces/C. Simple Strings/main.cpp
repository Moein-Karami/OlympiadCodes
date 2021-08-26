///Chefer


#include <bits/stdc++.h>
#define int long long int

using namespace std;

main()
{
    string s;
    cin>>s;

    for(int i=0;i<s.size();i++)
    {
        if(s[i+1]==s[i])
        {
            s[i+1]='x';
                if(s[i+1]==s[i+2])
            {
                s[i+1]='i';
            }
        }
        if(s[i+1]==s[i])
        {
            s[i+1]='u';
            if(s[i+1]==s[i+2])
            {
                s[i+1]='i';
            }
        }
    }
    cout<<s;
    return 0;
}
