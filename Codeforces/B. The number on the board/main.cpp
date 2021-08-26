#include <bits/stdc++.h>
#define int long long int
using namespace std;
int a[100010];
main()
{
    int k;
    cin>>k;
    string s;
    cin>>s;
    int n=s.size();
    int t=0,ans=0,tmp=0;
    for(int i=0;i<s.size();i++)
    {
        a[i]=s[i]-'0';
        t+=a[i];
        //if(a[i]==0)
            //tmp++;
    }
    sort(a,a+n);
    int i=0;
    while(t<k)
    {
        ans++;
        t+=9-a[i];
        i++;
    }
    cout<<max(tmp,ans);
    return 0;
}
