///DARK POGRAMMER



#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
int ans[10][10];
bool b[10][10];
queue <pii> q;
int main()
{
    int n=8;
    int t;
    cin>>t;
    int a1,a2;
    char c1,c2,c3;
    int b1,b2;
    for(int w=1;w<=t;w++)
    {
        cin>>c1;
        cin>>a1;
        b1=(c1-'a')+1;
        cin>>c2;
        cin>>a2;
        b2=(c2-'a')+1;
        //cout<<a1<<" "<<b1<<endl<<a2<<" "<<b2<<endl;
        for(int i=1;i<=8;i++)
            for(int j=1;j<=8;j++)
                b[i][j]=0;
        while(q.size())
            q.pop();
        pii tmp;
        tmp.f=a1;
        tmp.s=b1;
        q.push(tmp);
        b[a1][b1]=1;
        ans[a1][b1]=0;
        while(q.size())
        {
            tmp=q.front();
            if(tmp.f==a2&&tmp.s==b2)
            {
                cout<<ans[tmp.f][tmp.s]<<" ";
                break;
            }
            if(!b[tmp.f+2][tmp.s+1]&&tmp.f+2<=n&&tmp.s+1<=n)
            {
                b[tmp.f+2][tmp.s+1]=1;
                ans[tmp.f+2][tmp.s+1]=ans[tmp.f][tmp.s]+1;
                q.push(pii(tmp.f+2,tmp.s+1));
            }
            if(!b[tmp.f+1][tmp.s+2]&&tmp.f+1<=n&&tmp.s+2<=n)
            {
                b[tmp.f+1][tmp.s+2]=1;
                ans[tmp.f+1][tmp.s+2]=ans[tmp.f][tmp.s]+1;
                q.push(pii(tmp.f+1,tmp.s+2));
            }
            if(!b[tmp.f-1][tmp.s+2]&&tmp.f-1>0&&tmp.s+2<=n)
            {
                b[tmp.f-1][tmp.s+2]=1;
                ans[tmp.f-1][tmp.s+2]=ans[tmp.f][tmp.s]+1;
                q.push(pii(tmp.f-1,tmp.s+2));
            }
            if(!b[tmp.f-2][tmp.s+1]&&tmp.f-2>0&&tmp.s+1<=n)
            {
                b[tmp.f-2][tmp.s+1]=1;
                ans[tmp.f-2][tmp.s+1]=ans[tmp.f][tmp.s]+1;
                q.push(pii(tmp.f-2,tmp.s+1));
            }

            if(!b[tmp.f-2][tmp.s-1]&&tmp.f-2>0&&tmp.s-1>0)
            {
                b[tmp.f-2][tmp.s-1]=1;
                ans[tmp.f-2][tmp.s-1]=ans[tmp.f][tmp.s]+1;
                q.push(pii(tmp.f-2,tmp.s-1));
            }

            if(!b[tmp.f-1][tmp.s-2]&&tmp.f-1>0&&tmp.s-2>0)
            {
                b[tmp.f-1][tmp.s-2]=1;
                ans[tmp.f-1][tmp.s-2]=ans[tmp.f][tmp.s]+1;
                q.push(pii(tmp.f-1,tmp.s-2));
            }

            if(!b[tmp.f+1][tmp.s-2]&&tmp.f+1<=n&&tmp.s-2>0)
            {
                b[tmp.f+1][tmp.s-2]=1;
                ans[tmp.f+1][tmp.s-2]=ans[tmp.f][tmp.s]+1;
                q.push(pii(tmp.f+1,tmp.s-2));
            }

            if(!b[tmp.f+2][tmp.s-1]&&tmp.f+2<=n&&tmp.s-1>0)
            {
                b[tmp.f+2][tmp.s-1]=1;
                ans[tmp.f+2][tmp.s-1]=ans[tmp.f][tmp.s]+1;
                q.push(pii(tmp.f+2,tmp.s-1));
            }
            q.pop();
            for(int j=1;j<=8;j++)
            {
                //for(int k=1;k<=8;k++)
                    //cout<<ans[j][k]<<" ";
                //cout<<endl;
            }
            //cout<<endl;
        }
    }
    return 0;
}
