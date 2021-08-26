///Chefer


#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> pip;
const int maxn=2e5;
int a[maxn];
int gcd[8*maxn],cnt[8*maxn];
int gc(int a,int b)
{
    while(a&&b)
    {
        if(a<b)
            swap (a,b);
        a%=b;
    }
    return max(a,b);
}
void solve(int id,int l,int r)
{
    if(l+1==r)
    {

        gcd[id]=a[l];
        cnt[id]=1;
        return ;
    }
    int mid=(l+r)/2;
    solve(2*id,l,mid);
    solve(2*id+1,mid,r);
    if(gcd[2*id]==gcd[2*id+1])
    {
        gcd[id]=gcd[2*id];
        cnt[id]=(cnt[2*id]+cnt[2*id+1]);
    }
    else if(gcd[2*id]<gcd[2*id+1])
    {
        if(gc(gcd[2*id],gcd[2*id+1])==gcd[2*id])
        {
            gcd[id]=gcd[2*id];
            cnt[id]=cnt[2*id];
        }
        else
        {
            gcd[id]=gc(gcd[2*id],gcd[2*id+1]);
        }
    }
    else
    {
        if(gc(gcd[2*id],gcd[2*id+1])==gcd[2*id+1])
        {
            gcd[id]=gcd[2*id+1];
            cnt[id]=cnt[2*id+1];
        }
        else
            gcd[id]=gc(gcd[2*id],gcd[2*id+1]);
    }
    return;
}
pii say(int id,int L,int R,int l,int r)
{
    if(l==L&&r==R)
    {
        return pii(gcd[id],cnt[id]);
    }
    bool b1=0,b2=0;
    int g1,c1,g2,c2;
    pii tmp;
    int mid=(L+R)/2;
    if(l<mid)
    {
        tmp=say(2*id,L,mid,l,min(r,mid));
        g1=tmp.f;
        c1=tmp.s;
        b1=1;
    }
    if(r>mid)
    {
        b2=1;
        tmp=say(2*id+1,mid,R,max(l,mid),r);
        g2=tmp.f;
        c2=tmp.s;
    }
    if(b1&&b2)
    {
        if(g1==g2)
            return pii(g1,c1+c2);
        else if(g1<g2)
        {
            if(gc(g1,g2)==g1)
                return pii(g1,c1);
            else
                return pii(gc(g1,g2),0);
        }
        else
        {
            if(gc(g1,g2)==g2)
                return pii(g2,c2);
            else
                return pii(gc(g1,g2),0);
        }
    }
    else if(b1)
        return pii(g1,c1);
    else
        return pii(g2,c2);

}
main()
{
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>q;
    solve(1,0,n);
    int l,r,t;
    for(int i=0;i<q;i++)
    {
        cin>>l>>r;
        l--;
        t=r-l;
        cout<<t-say(1,0,n,l,r).s<<"\n";
    }
    return 0;
}
