#include <bits/stdc++.h>
#define int long long int
using namespace std;
bool b[30];
int a='a'-1;
main()
{
    string k,s,t;
    cin>>k;
    for(int i=0;i<k.size();i++)
        b[k[i]-a]=1;
    cin>>s;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        int cnt=0;
        bool c=1;
        for(int j=0;j<t.size();j++)
        {
            if(s[cnt]!='?'&&s[cnt]!='*'&&t[j]!=s[cnt])
            {
                cout<<"NO"<<endl;
                c=0;
                break;
            }
            else if(t[j]!=s[cnt])
            {
                if(s[cnt]=='?'&&!b[t[j]-a])

                {
                    cout<<"NO"<<endl;
                    c=0;
                    break;
                }
                else if(s[cnt]=='*')
                {
                    while(!b[t[j]-a])
                        j++;
                    j--;

                }
            }
            cnt++;
        }
        if(c)
            cout<<"YES"<<endl;
    }
    return 0;
}
