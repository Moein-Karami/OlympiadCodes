#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int cnt=0,cnt1=0,cnt2=0;
    string s[m];
    for(int i=0;i<m;i++)
        cin>>s[i];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            if(s[i][j]=='1')
            cnt2++;
        if(cnt2!=n)
            cnt1++;
        else
        {
            cnt=max(cnt1,cnt);
            cnt1=0;
        }
        cnt2=0;

    }
    cnt=max(cnt,cnt1);
    cout<<cnt;
    return 0;
}
