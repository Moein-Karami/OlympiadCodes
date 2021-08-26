///DARK PROGRAMMER


#include <iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;
    if(s[0]=='h'||s[0]=='a')
    {
        if(s[1]=='8'||s[1]=='1')
        {
            cout<<3;
            return 0;
        }
        cout<<5;
        return 0;
    }
    if(s[1]=='8'||s[1]=='1')
    {
        if(s[0]=='h'||s[0]=='a')
        {
            cout<<3;
            return 0;
        }
        cout<<5;
        return 0;
    }
    cout<<8;
    return 0;
}
