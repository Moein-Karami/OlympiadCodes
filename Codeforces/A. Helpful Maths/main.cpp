#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int a[1000000],cnt;
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(s[i]!='+')
        {
            a[cnt]=s[i]-48;
            cnt++;
        }
    }
    sort(a,a+cnt);
    cout<<a[0];
    for(int i=1;i<cnt;i++)
        cout<<"+"<<a[i];

    return 0;
}
