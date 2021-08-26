#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> pip;
const int mod=10559,maxn=1e6+6;
int p[maxn];
vector <int> v;
multiset<pip> se;
int a[maxn];
void def(int x,int y)
{
    vector<int> t;
    int tmp=x;
    for(int j=0;j<=y;j++)
    {
        int e=v[j];
        if(x*e<=n)
        {
            int s=0;
            if(x*e*e<=n)
                s++;
            se.insert(pii(s,0));
        }
    }
    for(int i=1;i<=3;i++)
    {
        int s=0;
        x*=tmp;
        if(x>n)
            break;
        for(int j=0;j<=y;j++)
        {
            int e=v[j];
            if(x*e<=n)
                s++;
        }
        t.push_back(s);
    }
    for(int i=t.size()-1;i>=0;i--)
        se.insert(pii(t[i],0-i-1));
}
main()
{
    cin>>n>>k;
    for(int i=0;i<maxm;i++)
        for(int j=0;j<maxm;j++)
            dp[i][j]=-1;
    for(int i=2;i<maxn;i++)
    {
        if(!p[i])
        {
            if(i<=n)
                v.push_back(i);
            for(int j=i;j<maxn;j+=i)
                p[j]=i;
        }
    }
    for(int i=0;i<v.size();i++)
        def(v[i],i);
    int t=0;
    set<pii>::iterator it;
    int x;
    while(se.size())
    {
        it=se.begin();
        x=(*it).f;
        if((*it).s<0)
    }
    return 0;
}
