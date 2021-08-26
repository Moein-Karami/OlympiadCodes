///DARK PROGRAMMER


#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
string s;
int m,n;
const int maxn=19,maxm=100+3;
int dp[maxm][1<<maxn];
int nxt[maxn+10];
inline int chefer(const int &mask ,const  int &x)
{
    if(dp[x][mask]!=-1)
        return dp[x][mask];
    if(mask==((1<<n)-1))
        return x==0;
    int &ret=dp[x][mask];
    int pre=n;
    for(int i=nxt[pre];i<n;++i)
        if(((1<<i)^mask)>mask)
            //if(s[i]!=s[pre])
            {
                ret+=chefer(mask|(1<<i),((10*x+(s[i]-48))%m));
                pre=i;
                i=nxt[i]-1;
            }
    ret++;
    return ret;
}
int a[20];
main()
{
    for(int i=0;i<maxm;i++)
        for(int j=0;j<(1<<maxn);j++)
            dp[i][j]=-1;
    ios::sync_with_stdio(false);
    cin>>s>>m;
    n=s.size();
    int ans=0;
    sort(s.begin(),s.end());
    s+="$";
    nxt[n]=0;
    for(int i=n-1;i>=0;i--)
        if(s[i]==s[i+1])
            nxt[i]=nxt[i+1];
        else
            nxt[i]=i+1;
    for(int i=0;i<n;i++)
        if(s[i]!='0'&&s[i]!=s[i+1])
            ans+=chefer((1<<i),(s[i]-48)%m);
    for(int i=0;i<n;i++)
        a[s[i]-48]++;
    int fact=1;
    cout<<ans;
    return 0;
}
