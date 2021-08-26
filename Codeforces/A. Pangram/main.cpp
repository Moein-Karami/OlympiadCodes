#include <iostream>

using namespace std;
bool b[30];

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        if(s[i]>'Z')
            s[i]-=32;
        b[s[i]-64]=1;
    }
    for(int i=1;i<=26;i++)
    {
        if(!b[i])
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}
