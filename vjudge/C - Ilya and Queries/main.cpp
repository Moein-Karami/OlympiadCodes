#include <iostream>
#include <string>

using namespace std;
int dp[100000],q[100000];
int main()
{
    int n,temp=0,cnt=0;
    string s ;
    cin>>s;
    n=s.length();
    for(int i=1 ; i<=n;i++)
    {
        if(s[i]==s[i-1])
            cnt++;
    }
     dp[1]=cnt;
     for(int i=2;i<=n;i++)
     {
         if(s[i-1]==s[i-2])
            dp[i]=dp[i-1]-1;
         else
            dp[i]=dp[i-1];
     }
     int l,r,m;
     cin>>m;
     for ( int i=1;i<=m;i++)
     {
         cin>>l>>r;
         q[i]=dp[l]-dp[r];
     }
     for(int i=1;i<=m;i++)
        cout<<q[i]<<endl;
    return 0;
}
