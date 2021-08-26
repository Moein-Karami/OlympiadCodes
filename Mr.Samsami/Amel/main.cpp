#include <bits/stdc++.h>
#define int long long int
using namespace std;
bool b[100000001];
int dp[100000001];
int ans;
vector <int> v;
main()
{
    b[1]=1;

    for(int i=2;i<=1e8;i++)
    {
        if(!b[i])
        {
            dp[i]=i;
            v.push_back(i);
            if(i*i<=1e8)
                for(int j=i*i;j<=1e8;j+=i)
                {
                    b[j]=1;
                    dp[j]=i;
                }
        }
    }

    for(int i=2;i<=100000000;i++)
    {
        int t=i;
        int cnt=0;
        while(t!=1)
        {
            cnt++;
            if(cnt>2)
            {
                t=1;
            }
            else
                t/=dp[t];
        }
        if(cnt==2)
            ans++;
    }
    cout<<ans;
    return 0;
}
