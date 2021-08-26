///DARK PROGRAMMER



#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii ;
const int maxn=10;
bool b[maxn][maxn];
string ans[maxn][maxn];
int h[maxn][maxn];
pii parent[maxn][maxn];
char c1[3],c2[3];
vector <pii> answer;
queue <pii> q;
int main()
{
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            if(i==0||i==9||j==0||j==9)
                b[i][j]=1;
    c1[0]='L';
    c1[1]=' ';
    c1[2]='R';
    c2[0]='D';
    c2[1]=' ';
    c2[2]='U';
    char a,u,v,d;
    cin>>a>>u>>v>>d;
    int s1,s2,p1,p2;
    s1=u-'0';
    s2=a-'a'+1;
    p1=d-'0';
    p2=v-'a'+1;
    b[s1][s2]=1;
    ans[s1][s2]="END";
    q.push(pii(s1,s2));
    while(q.size())
    {
       pii tmp=q.front();
       for(int i=-1;i<=1;i++)
       {
           for(int j=-1;j<=1;j++)
           {
               if(!b[tmp.f+i][tmp.s+j])
               {
                   h[tmp.f+i][tmp.s+j]=h[tmp.f][tmp.s]+1;
                   ans[tmp.f+i][tmp.s+j].push_back(c1[j+1]);
                   ans[tmp.f+i][tmp.s+j].push_back(c2[i+1]);
                   parent[tmp.f+i][tmp.s+j].f=tmp.f;
                   parent[tmp.f+i][tmp.s+j].s=tmp.s;
                   q.push(pii(tmp.f+i,tmp.s+j));
                   b[tmp.f+i][tmp.s+j]=1;
               }
           }
       }
       q.pop();
    }
    cout<<h[p1][p2]<<endl;
    pii tmp;
    tmp.f=p1;
    tmp.s=p2;
    while(ans[tmp.f][tmp.s]!="END")
    {
        answer.push_back(tmp);
        tmp=parent[tmp.f][tmp.s];
    }
    for(int i=answer.size()-1;i>=0;i--)
    {
        tmp=answer[i];
        cout<<ans[tmp.f][tmp.s]<<endl;
    }
    return 0;
}
