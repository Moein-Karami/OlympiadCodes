#include <iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(s[n-1]>s[i]&&(s[i]-48)%2==0)
        {
            char z=s[i];
            s[i]=s[n-1];
            s[n-1]=z;
            cout<<s;
            return 0;
        }
    }
    for(int i=n-2;i>=0;i--)
    {
        if((s[i]-48)%2==0)
        {
            char z=s[i];
            s[i]=s[n-1];
            s[n-1]=z;
            cout<<s;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}
