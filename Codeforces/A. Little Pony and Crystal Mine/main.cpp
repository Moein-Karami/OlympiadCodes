///DARK PROGRAMMER


#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    for(int i=0;i<n;i++)
        s.push_back('*');
    s[n/2]='D';
    cout<<s<<endl;
    for(int i=1;i<n;i++)
    {
        if(i<=n/2)
        {
            for(int j=0;j<n;j++)
            {
                if(s[j]=='D')
                {
                    s[j-1]='D';
                    break;
                }
            }
            for(int j=n-1;j>=0;j--)
            {
                if(s[j]=='D')
                {
                    s[j+1]='D';
                    break;
                }
            }
            cout<<s<<endl;
        }
        else
        {
          for(int j=0;j<n;j++)
            {
                if(s[j]=='D')
                {
                    s[j]='*';
                    break;
                }
            }
            for(int j=n-1;j>=0;j--)
            {
                if(s[j]=='D')
                {
                    s[j]='*';
                    break;
                }
            }
            cout<<s<<endl;
        }
    }
    return 0;
}
