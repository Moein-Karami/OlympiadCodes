///DARK PROGRAMMER


#include <iostream>
int a[7];
using namespace std;

int main()
{
    string s;
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(s[i]=='B')
            a[0]++;
        if(s[i]=='u')
            a[1]++;
        if(s[i]=='l')
            a[2]++;
        if(s[i]=='b')
            a[3]++;
        if(s[i]=='a')
            a[4]++;
        if(s[i]=='s')
            a[5]++;
        if(s[i]=='r')
            a[6]++;
    }
    a[1]/=2;
    a[4]/=2;
    int ans=1e9;
    for(int i=0;i<7;i++)
        if(a[i]<ans)
        ans=a[i];
    cout<<ans;
    return 0;
}
