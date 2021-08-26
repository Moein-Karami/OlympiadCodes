#include <iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int n=s.size();
    bool b=1;
    for(int i=1;i<n;i++)
    {
        if(s[i]>'Z')
            b=0;
    }
    if(b)
    {
        if(s[0]>'Z')
        {
            s[0]-=32;
            for(int i=1;i<n;i++)
                s[i]+=32;
        }
        else
            for(int i=0;i<n;i++)
                s[i]+=32;

    }

    cout<<s;
    return 0;
}
