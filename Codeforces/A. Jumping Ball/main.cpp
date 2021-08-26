#include <iostream>
#include <string>

using namespace std;
int ans;
int main()
{
    int n;
    cin>>n;
    string str;
    cin>>str;
    int s=str.size();
    for(int i=0;i<s;i++)
    {
        if(str[i]=='<')
            ans++;
        else
         i=n;
    }
    for(int i=s-1;i>=0;i--)
    {
        if(str[i]=='>')
            ans++;
        else
         i=-1;
    }
    cout<<ans;
    return 0;
}
