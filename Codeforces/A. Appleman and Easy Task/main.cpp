#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    char s[n+2][n+2];
    for(int i=0;i<n+2;i++)
    {
        for(int j=0;j<n+2;j++)
        {
           s[i][j]='F';
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
           cin>>s[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int cnt=0;
            if(s[i+1][j]=='o')
                cnt++;
            if(s[i][j+1]=='o')
                cnt++;
            if(s[i-1][j]=='o')
                cnt++;
            if(s[i][j-1]=='o')
                cnt++;
            if(cnt%2)
            {
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES";
    return 0;
}
