///DARK PROGRAMMER



#include <iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int n=s.size();
    bool a=0,b=0;
    for(int i=0;i<n;i++)
    {
        if(!a&&s[i]=='A'&&s[i+1]=='B')
        {
            a=1;
            i++;
        }
        else if(!b&&s[i]=='B'&&s[i+1]=='A')
        {
            b=1;
            i++;
        }
    }
    if(a&&b)
    {
        cout<<"YES";
        return 0;
    }
    else
    {
        a=0,b=0;
        int j=0,q=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='B'&&s[i+1]=='A')
            {
                b=1;
                j=i;
                q=i+1;
                i++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(s[i]=='A'&&s[i+1]=='B'&&i+1!=j&&i!=q)
            {
                a=1;
                i++;
            }
        }
    }
    if(a&&b)
    {
        cout<<"YES";
        return 0;
    }
        cout<<"NO";
    return 0;
}
