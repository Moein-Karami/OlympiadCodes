#include <iostream>

using namespace std;
int s[100];
int a[101][101];
char c;
int main()
{
    for(int i=1;i<=100;i++)
    {
        for(int j=51;j<=100;j++)
        {
            cin>>c;
            s[j]+=c-'0';
        }
    }
    for(int i=100;i>=0;i--)
    {
        s[i-1]+=s[i]/10;
        s[i]%=10;
    }
    for(int i=0;i<=100;i++)
        cout<<s[i];
    return 0;
}
