///Chefer


#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
const int maxn=1e5+5;
int se[5][4*maxn];
int sesi[4*maxn];
vector <string> q1;
vector <int> q2;
vector <int> com;
int a[maxn];
map <int,int> mp;
void add(int id,int L,int R,int idx)
{
    if(L+1==R)
    {
        se[1][id]=a[idx];
        sesi[id]++;
        return ;
    }
    int mid=(L+R)/2;
    if(idx<mid)
        add(2*id,L,mid,idx);
    else
        add(2*id+1,mid,R,idx);
    int x=2*id,y=2*id+1;
    sesi[id]=sesi[x]+sesi[y];
    for(int i=0;i<5;i++)
        se[i][id]=se[i][x]+se[(i-(sesi[x]%5)+5)%5][y];
}
void rem(int id,int L,int R,int idx)
{
    if(L+1==R)
    {
        se[1][id]=0;
        sesi[id]--;
        return ;
    }
    int mid=(L+R)/2;
    if(idx<mid)
        rem(2*id,L,mid,idx);
    else
        rem(2*id+1,mid,R,idx);
    int x=2*id,y=2*id+1;
    sesi[id]=sesi[x]+sesi[y];
    for(int i=0;i<5;i++)
        se[i][id]=se[i][x]+se[(i-(sesi[x]%5)+5)%5][y];
}
main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        int t;
        cin>>s;
        q1.push_back(s);
        if(s[0]=='s')
        {
            q2.push_back(0);
            continue ;
        }
        cin>>t;
        q2.push_back(t);
        com.push_back(t);
    }
    sort(com.begin(),com.end());
    int cnt=0;
    for(int i=0;i<com.size();i++)
    {
        if(!mp[com[i]])
        {
            cnt++;
            mp[com[i]]=cnt;
            a[cnt]=com[i];
        }
    }
    for(int i=0;i<q1.size();i++)
        if(q1[i][0]!='s')
            q2[i]=mp[q2[i]];
    for(int i=0;i<q1.size();i++)
    {
        if(q1[i][0]=='s')
            cout<<se[3][1]<<"\n";
        else
        {
            if(q1[i][0]=='d')
                rem(1,1,maxn,q2[i]);
            else
                add(1,1,maxn,q2[i]);
        }
    }
    return 0;
}
