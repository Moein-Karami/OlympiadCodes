///Chefer


#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn=1e6+6;
int l[maxn],r[maxn];
main()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        if(!l[s[i]-'A'+1])
            l[s[i]-'A'+1]=i+1;
    }
    for(int i=n-1;i>=0;i--)
    {
        if(!r[s[i]-'A'+1])
            r[s[i]-'A'+1]=i+1;
    }
    for(int i=1;i<=n;i++)
    {
        int cnt=0;
        for(int j=1;j<=26;j++)
            if(l[j]<=i&&r[j]>=i)
                cnt++;
        if(cnt>k)
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}
