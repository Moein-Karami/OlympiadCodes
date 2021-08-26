///C


#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    string s;
    int ans,cnt,tmp;
    for(int T=1;T<=n;T++)
    {
        string s;
        cin>>s;
        ans=0;
        cnt=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0')
                cnt++;
            else
            {
                tmp=0;
                for(int j=i;j<s.size();j++)
                {
                    tmp*=2;
                    if(s[j]=='1')
                        tmp++;
                    if(cnt+(j-i+1)>=tmp)
                        ans++;
                    else
                        break;
                }
                cnt=0;
            }
        }
        cout<<ans<<endl;
    }
}
