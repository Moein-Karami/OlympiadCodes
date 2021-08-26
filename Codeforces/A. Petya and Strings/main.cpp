#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.size();
    for(int i=0;i<n;i++)
    {
        if(s1[i]<'a')
            s1[i]+=32;
        if(s2[i]<'a')
            s2[i]+=32;

        if(s1[i]>s2[i])
        {
            cout<<1;
            return 0;
        }
        if(s2[i]>s1[i])
        {
            cout<<-1;
            return 0;
        }
    }
    cout<<0;
    return 0;
}
