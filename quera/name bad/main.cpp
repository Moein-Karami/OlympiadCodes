#include <iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;
    char c;
    int t=0,n;
    n=s.size();
    if(n==1||s[n-1]!=s[n-2])
    {
        cout<<"bad";
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        if(s[i]==c)
        {
            t++;
        }

        else
        {
            if(t%2==1)
            {
                cout<<"bad";
                return 0;
            }
            t=1;
            c=s[i];
            if(i==n-1)
                t=0;
        }
    }
    if(t%2==1)
    {
        cout<<"bad";
        return 0;
    }
    cout<<"khoob";
    return 0;
}
