#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int n=s.size();
    if(s[0]!='9'&&s[0]>'4')
        cout<<9-(s[0]-48);
    else
        cout<<a[0];
    for(int i=1;i<n;i++)
    {
        if(s[i]>'4')
            cout<<9-(s[i]-48);
        else
            cout<<s[i];
    }
    return 0;
}
