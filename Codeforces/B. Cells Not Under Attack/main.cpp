#include <iostream>

using namespace std;
bool s[100100],r[100100];
int main()
{
    int n,m;
    cin>>n>>m;
    int ans=n*n;
    int x,y;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        if(!s[y]&&!r[x])
        {
            ans=ans-2*n+1+(i-1)*2;
            s[y]=1;
            r[x]=1;
        }
        if(s[y]&&!r[x])
        {
            ans=ans-n+1+i-1;
            r[x]=1;
        }
        if(!s[y]&&r[x])
        {
            ans=ans-n+1+i-1;
            s[y]=1;
        }
        cout<<ans<<" ";
    }
    return 0;
}
