///DARK PROGRAMMER



#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef pair<int,int> pii;
const int maxn=1e5+10;
bool zombie[maxn],b[maxn];
vector <int> v[maxn];
bool z[maxn];
int zom[maxn];
int dp[maxn];
int hf[maxn],hmax[maxn];
pii hs1[maxn],hs2[maxn];
void bez(int p,int x)
{
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i]!=p)
        {
            bez(x,v[x][i]);
            zombie[x]=max(zombie[x],zombie[v[x][i]]);
        }

    }
}
void dfson(int p,int x)
{
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i]!=p&&zombie[v[x][i]])
        {
            dfson(x,v[x][i]);
            if(hs1[v[x][i]].f>=hs1[x].f)
            {
                hs1[x].f=hs1[v[x][i]].f+1;
                hs1[x].s=v[x][i];
            }
        }
    }
    for(int i=0;i<v[x].size();i++)
    {
        if(zombie[v[x][i]]&&v[x][i]!=hs1[x].s&&v[x][i]!=p&&hs2[x].f<=hs1[v[x][i]].f)
        {
            hs2[x].f=hs1[v[x][i]].f+1;
            hs2[x].s=v[x][i];
        }
    }

}
void dfather(int p,int x)
{
    //if(x!=p)
    //{
        if(hs1[p].s!=x&&hs1[p].s)
            hf[x]=max(hf[p],hs1[p].f)+1;
        else if(hs2[p].s!=x&&hs2[p].s)
            hf[x]=max(hf[p],hs2[p].f)+1;
        else if(hf[p]||z[p])
            hf[x]=hf[p]+1;
        if(x==1)
            hf[x]=0;
        for(int i=0;i<v[x].size();i++)
            if(v[x][i]!=p)
                dfather(x,v[x][i]);
    //}
}
int main()
{
    int n,m,d;
    cin>>n>>m>>d;
    for(int i=1;i<=m;i++)
    {
        cin>>zom[i];
        z[zom[i]]=1;
        zombie[zom[i]]=1;
    }
    int a,c;
    for(int i=1;i<n;i++)
    {
        cin>>a>>c;
        v[a].push_back(c);
        v[c].push_back(a);
    }
    bez(1,1);
    dfson(1,1);
    dfather(1,1);
    for(int i=1;i<=n;i++)
        hmax[i]=max(hs1[i].f,hf[i]);

    int ans=0;

    for(int i=1;i<=n;i++)
        if(hmax[i]<=d)
            ans++;
    cout<<ans;
    return 0;
}
