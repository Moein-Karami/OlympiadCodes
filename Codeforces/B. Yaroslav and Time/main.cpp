///Chefer


#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
const int maxn=110;
vector<pii> v[maxn];
pii cj[maxn];
int t[maxn];
int n,d;
int binary(int l,int r)
{
    bool c=0;
    if(l+1==r)
        return l;
    int mid=(l+r)/2;
    int val[n+1];
    bool b[n+1];
    for(int i=0;i<=n;i++)
        val[i]=0,b[i]=0;
    val[1]=mid;
    b[1]=1;
    for(int i=0;i<v[1].size();i++)
        if(mid>=d*v[1][i].f)
            val[v[1][i].s]=mid-d*v[1][i].f+t[v[1][i].s];
    for(int i=2;i<=n;i++)
    {
        int maxi=0;
        for(int j=2;j<=n;j++)
            if(!b[j]&&val[maxi]<val[j])
                maxi=j;
        b[maxi]=1;
        for(int j=0;j<v[maxi].size();j++)
        {
            if(val[maxi]>=d*v[maxi][j].f&&val[v[maxi][j].s]<val[maxi]-d*v[maxi][j].f+t[v[maxi][j].s])
            {
                if(v[maxi][j].s==n)
                    c=1;
                val[v[maxi][j].s]=val[maxi]-d*v[maxi][j].f+t[v[maxi][j].s];
            }
        }
    }
    if(c||val[n])
        return binary(l,mid);
    else
        return binary(mid,r);
}
main()
{
    cin>>n>>d;
    for(int i=2;i<n;i++)
        cin>>t[i];
    for(int i=1;i<=n;i++)
        cin>>cj[i].f>>cj[i].s;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            v[i].push_back(pii(fabs(cj[i].f-cj[j].f)+fabs(cj[i].s-cj[j].s),j));
            v[j].push_back(pii(fabs(cj[i].f-cj[j].f)+fabs(cj[i].s-cj[j].s),i));
        }
    }
    cout<<binary(1,1e9);
    return 0;
}
