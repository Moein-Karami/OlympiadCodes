///DARK PROGRAMMER



#include <bits/stdc++.h>
#define s second
#define f first
using namespace std;
typedef pair<int,int> pii;

char c[3][1000000];
bool b[3][1000000];
int ans[3][1000000];
queue <pii> q;
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=2;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>c[i][j];
            if(c[i][j]=='X')
                b[i][j]=1;
        }
    }
    q.push(pii(1,1));
    b[1][1]=1;
    ans[1][1]=0;
    while(q.size())
    {
        pii tmp=q.front();

        while(q.size()&&ans[tmp.f][tmp.s]>=tmp.s)
        {
            q.pop();
            tmp=q.front();
        }

        if(!q.size())
            break;

        if(tmp.s+k>n&&ans[tmp.f][tmp.s]<tmp.s)
        {
                cout<<"YES";
                return 0;
        }
        if(!b[tmp.f][tmp.s-1]&&tmp.s>1)
        {
            b[tmp.f][tmp.s-1]=1;
            ans[tmp.f][tmp.s-1]=ans[tmp.f][tmp.s]+1;
            q.push(pii(tmp.f,tmp.s-1));
        }
        if(!b[tmp.f][tmp.s+1]&&tmp.s<n)
        {
            b[tmp.f][tmp.s+1]=1;
            ans[tmp.f][tmp.s+1]=ans[tmp.f][tmp.s]+1;
            q.push(pii(tmp.f,tmp.s+1));
        }
        if(!b[3-tmp.f][tmp.s+k])
        {
            b[3-tmp.f][tmp.s+k]=1;
            ans[3-tmp.f][tmp.s+k]=ans[tmp.f][tmp.s]+1;
            q.push(pii(3-tmp.f,tmp.s+k));
        }
        q.pop();
    }
    if(ans[2][n]||ans[1][n])
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
