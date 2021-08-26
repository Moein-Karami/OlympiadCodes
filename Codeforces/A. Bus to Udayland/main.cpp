#include <iostream>

using namespace std;

int main()
{
    int n;
    bool b=0;
    cin>>n;
    string s[n];
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<4;j++)
        {
          if(s[i][j]=='O'&&s[i][j+1]=='O')
          {
              s[i][j]='+';
              s[i][j+1]='+';
              j=5;
              i=n;
              cout<<"YES"<<endl;
              b=1;
          }
        }
    }
    if(b)
    {
        for(int i=0;i<n;i++)
    {
        cout<<s[i]<<endl;
    }
    return 0;
    }
    cout<<"NO";
    return 0;
}
