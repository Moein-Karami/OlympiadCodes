#include <bits/stdc++.h>

using namespace std;
string s[100000];
string a[100000];
int dp[100000];
int main()
{
    int t=0;
    fstream in("gg.txt",ios::in);
    while(in>>s[t])
        t++;
    int tmp=0;
    for(int i=0;i<t;i++)
    {
        bool b=1;
        for(int j=0;j<tmp;j++)
            if(s[i]==a[j])
                b=0,dp[j]++;
        if(b)
        {
            a[tmp]=s[i];
            dp[tmp]++;
            tmp++;
        }
    }
    int ans=t;
    for(int i=0;i<tmp;i++)
    {
        for(int j=i+1;j<tmp;j++)
        {
            if(a[i].size()==a[j].size())
            {
                int b=min(dp[i],dp[j]);
                for(int q=0;q<a[i].size();q++)
                    if(a[i][q]!=a[j][a[i].size()-1-q])
                        b=0;
                ans-=b;
            }
        }
    }
    cout<<ans;
    return 0;
}
