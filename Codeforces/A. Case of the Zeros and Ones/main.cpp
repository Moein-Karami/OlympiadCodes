#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt1=0,cnt0=0;
    for(int i=0;i<n;i++)
    {
      if(s[i]=='1')
            cnt1++;
     if(s[i]=='0')
            cnt0++;

    }
    int maxi=max(cnt1,cnt0),mini=min(cnt1,cnt0);
    cout<<maxi-mini;
    return 0;
}
