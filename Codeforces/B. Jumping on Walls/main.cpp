///C


#include <bits/stdc++.h>
//#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
const int maxn=1e5+5;
char c[5][maxn];
int n,k;
queue<pii>q;
int dis[4][maxn];
main()
{
    ios_base::sync_with_stdio(false);
    for(int i=0;i<4;i++)
        for(int j=0;j<maxn;j++)
            dis[i][j]=5*maxn;
    cin>>n>>k;
    for(int i=1;i<=2;i++)
        for(int j=1;j<=n;j++)
            cin>>c[i][j];
    dis[1][1]=0;
    q.push(pii(1,1));
    int f,s;
    pii t;
    while(q.size())
    {
        t=q.front();
        f=t.f;
        s=t.s;
        q.pop();
        if(dis[f][s]>=s||c[f][s]=='X')
            continue;
        if(s+k>n)
        {
            cout<<"YES";
            return 0;
        }
        if(dis[3-f][s+k]>dis[f][s]+1)
        {
            dis[3-f][s+k]=1+dis[f][s];
            q.push(pii(3-f,s+k));
        }
        for(int i=-1;i<=1;i++)
        {
            if(dis[f][s]+1<dis[f][s+i])
            {
                dis[f][s+i]=dis[f][s]+1;
                q.push(pii(f,s+i));
            }
        }
    }
    cout<<"NO";
    return 0;
}
