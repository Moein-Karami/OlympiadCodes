#include <iostream>
#define f first
#define s second
using namespace std;
int dp[(1<<19)+1][19];
int a[19];
int n,m,q,f=0;
pair <int , pair <int ,int > > rul[400];
int solve(int mask , int x)
{
  if(dp[mask][x])
  {
       return dp[mask][x];
  }
  int maxi0=0;
  if(mask==(1<<x))
            return dp[mask][x]=a[x];
  for(int i=0;i<n;i++)
  {
        if(i!=x)
        {
            if(mask&(1<<i))
            {
                dp[mask-(1<<x)][i]=solve(mask-(1<<x),i)+a[i];
                maxi0=max(maxi0,dp[mask-(1<<x)][i]);
            }
        }
  }

  int maxi=0;
  bool b=1;
  for(int i=0;i<n;i++)
  {
    if(i!=x)
    {
        if(mask&1<<i)
        {
             for(int j=0;j<q;j++)
             {
                 if(i==rul[j].f-1&&x==rul[j].s.f-1)
                 {

                     maxi=max(maxi,dp[mask-(1<<i)][i]+rul[j].s.s);
                     b=0;
                 }

             }
        }
    }
  }


  if(b)
    return maxi0;
  else
    return maxi;
}
int main()
{
    cin>>n>>m>>q;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<q;i++)
        cin>>rul[i].f>>rul[i].s.f>>rul[i].s.s;
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        dp[(1<<n)-1][i]=solve((1<<n)-1,i)+a[i];
        maxi=max(maxi,dp[(1<<n)-1][i]);
    }
    cout<<maxi;
    return 0;
}
