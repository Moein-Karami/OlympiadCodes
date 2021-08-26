#include <bits/stdc++.h>
#define int long long int

using namespace std;
int a[200];
int mod=22943;
main()
{
    for(int i=1;i<=150;i++)
        for(int j=1;j<=i;j++)
            if(i%j==0)
                a[i]++;
    for(int i=1;i<=150;i++)
        cout<<a[i];
        cout<<endl;
    string s="9886848442122467482648212246648210542124448212464441226692828842122841028466441634464122848212448828212444154466212";
    int ans=0;
    for(int i=0;i<s.size();i++)
        ans+=(s[i]-'0');
    cout<<ans%mod;
    return 0;
}
