#include <iostream>
#include <string>
using namespace std;
string s[110];
int main()
{
    int n,m,cnt=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            if(s[i][j]=='*')
            cnt++;
    }
    cout<<cnt;
    return 0;
}
