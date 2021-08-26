#include <iostream>

using namespace std;
int ans[1000];
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt=0,cnt1=0;
    for(int i=0;i<n;i++)
    {
        cnt1=0;

        while(s[i]=='B')
        {
            cnt1++;
            i++;
        }
        if(s[i-1]=='B')
        {
            ans[cnt]=cnt1;
            cnt++;
        }

    }
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++)
        cout<<ans[i]<<" ";
    return 0;
}
