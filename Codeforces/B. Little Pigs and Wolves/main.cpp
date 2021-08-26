#include <iostream>
#include <string>

using namespace std;
int ans;
int main()
{
    int n,m;
    cin>>n>>m;
    char str[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>str[i][j];
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(str[i][j]=='W')
            {
                if(str[i-1][j]=='P'||str[i][j-1]=='P'||str[i][j+1]=='P'||str[i+1][j]=='P')
                    ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
