///DARK PROGRAMMER


#include <iostream>

using namespace std;
int n,k;
int dp[100][100];
bool a[100],r[100],ghr[100],ghch[100];
int ans;
void solve(int x)
{
    if(x==n+1)
    {
        ans++;
        return;
    }
    if(!r[x])
        solve(x+1);
    else
    {
           for(int i=1;i<=n;i++)
        {
            if(!a[i]&&!ghr[i-x]&&!ghch[i+x])
            {
                a[i]=1;
                ghr[i-x]=1;
                ghch[i+x]=1;
                dp[x][i]=1;
                solve(x+1);
                dp[x][i]=0;
                a[i]=0;
                ghr[i-x]=0;
                ghch[i+x]=0;
            }
        }
    }
}
void tashkhis(int x,int cnt)
{
    if(x>n+1)
        return;
    if(cnt==k)
    {
        solve(1);
        return;
    }
    r[x]=1;
    tashkhis(x+1,cnt+1);
    r[x]=0;
    tashkhis(x+1,cnt);
    return;
}
int main()
{
    cin>>n>>k;
    if(k>n)
    {
        cout<<0;
        return 0;
    }
    tashkhis(1,0);
    cout<<ans;
    return 0;
}
