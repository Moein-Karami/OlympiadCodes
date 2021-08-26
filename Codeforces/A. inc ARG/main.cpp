///DARK PROGRAMMER



#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    string t;
    t=s;
    s[0]++;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='2')
        {
            s[i]=0;
            s[i+1]++;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]!=t[i])
            ans++;
    }
    cout<<ans;
    return 0;
}
