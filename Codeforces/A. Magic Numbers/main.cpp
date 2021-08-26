///DARK PROGRAMMER



#include <iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int n=s.size();
    if(s[0]=='4')
    {
        cout<<"NO";
        return 0;
    }
    for(int i=0;i<n;i++)
    {

        if(s[i]!='1'&&s[i]!='4')
        {
            cout<<"NO";
            return 0;
        }
        if(s[i]=='4'&&s[i+1]=='4')
        {
            if(s[i+2]=='4')
            {
                cout<<"NO";
                return 0;
            }
            if(i+2<n&&s[i+2]!='1')
            {
                cout<<"NO";
                return 0;
            }
            else
                i+=2;
        }
    }
    cout<<"YES";
    return 0;
}
