#include <iostream>

using namespace std;

int main()
{
    string s,s1;
    cin>>s>>s1;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(s[i]==s1[i])
            cout<<0;
        else
            cout<<1;
    }

    return 0;
}
