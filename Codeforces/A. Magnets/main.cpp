#include <iostream>

using namespace std;

int main()
{
    int n,cnt=1;
    cin>>n;
    string s[n];
    for(int i=0;i<n;i++)
        cin>>s[i];
    for(int i=1;i<n;i++)
    {
        if(s[i][0]==s[i-1][1])
            cnt++;
    }
    cout<<cnt;
    return 0;
}
