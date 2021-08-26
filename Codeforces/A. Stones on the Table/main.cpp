#include <iostream>

using namespace std;

int main()
{
    int n;
    bool b=1;
    cin>>n;
    string s;
    cin>>s;
    int ans=0,x;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            x=j;
           if(s[j]!=s[i])
                j=n;
           else
            ans++;
           b=1;

        }
        if(b)
            i=x-1;
        b=0;
    }
    cout<<ans;
    return 0;
}
