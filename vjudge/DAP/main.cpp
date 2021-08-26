///Chefer


#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int,int > pii;
typedef pair<pii,pii> pip;
const int maxn=2e5;
int sat[4*maxn];
int pat[4*maxn];
int ANS[4*maxn];
int DIS[4*maxn];
int d[maxn];
int h[maxn];
void solve(int id,int L,int R)
{
    if(L+1==R)
    {
        sat[id]=2*h[L]+d[L];
        pat[id]=2*h[L];
        DIS[id]=d[L];
        //cerr<<"L & R & A & S & P & D : " <<L<<" "<<R<<" "<<ANS[id]<<" "<<sat[id]<<" "<<pat[id]<<" "<<DIS[id]<<"\n";
        return ;
    }//cerr<<"L & R : "<<L<<" "<<R<<endl;
    int mid=(L+R)/2;
    solve(2*id,L,mid);
    solve(2*id+1,mid,R);
    int x=2*id;
    int y=2*id+1;
    ANS[id]=max(max(ANS[x],ANS[y]),sat[x]+pat[y]);
    DIS[id]=DIS[x]+DIS[y];
    sat[id]=max(sat[x]+DIS[y],sat[y]);
    pat[id]=max(pat[x],DIS[x]+pat[y]);
    //cerr<<"L & R & A & S & P & D : " <<L<<" "<<R<<" "<<ANS[id]<<" "<<sat[id]<<" "<<pat[id]<<" "<<DIS[id]<<"\n";
}
pip say(int id,int L,int R,int l,int r)
{
    if(l>=r)
        return pip(pii(0,0),pii(0,0));
    if(l==L&&r==R)
    {
        return pip(pii(ANS[id],DIS[id]),pii(sat[id],pat[id]));
    }
    pip t1,t2;
    t1.f.f=0;
    t1.f.s=0;
    t1.s.f=0;
    t1.s.s=0;
    t2.f.f=0;
    t2.f.s=0;
    t2.s.f=0;
    t2.s.s=0;
    int mid=(L+R)/2;
    if(l<mid)
        t1=say(2*id,L,mid,l,min(mid,r));
    if(r>mid)
        t2=say(2*id+1,mid,R,max(mid,l),r);
    int p,s,d,ans;
    d=t1.f.s+t2.f.s;
    s=max(t1.s.f+t2.f.s,t2.s.f);
    p=max(t2.s.s+t1.f.s,t1.s.s);
    ans=max(max(t1.f.f,t2.f.f),t1.s.f+t2.s.s);
    //cerr<<"L & R & A & S & P & D : " <<l<<" "<<r<<" "<<ans<<" "<<s<<" "<<p<<" "<<d<<"\n";
    return pip(pii(ans,d),pii(s,p));
}
main()
{
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++)
        cin>>d[i];
    for(int i=0;i<n;i++)
        cin>>h[i];
    solve(1,0,n);
    int l,r;
    int mid=(n/2)+1;
    int ret=0;
    for(int o=0;o<q;o++)
    {
        ///
        pip t1,t2;
        t1.f.f=0;
        t1.f.s=0;
        t1.s.f=0;
        t1.s.s=0;
        t2.f.f=0;
        t2.f.s=0;
        t2.s.f=0;
        t2.s.s=0;
        ///
        cin>>l>>r;
        l--;
        r--;
        if(l<=r)
        {
            t1=say(1,0,n,r+1,n);
            t2=say(1,0,n,0,l);
            ret=max(t1.f.f,t2.f.f);
            if(t1.s.f&&t2.s.s)
                cout<<max(ret,t1.s.f+t2.s.s)<<"\n";
            else
                cout<<ret<<"\n";
        }
        else
            cout<<say(1,0,n,r+1,l).f.f<<"\n";

    }
    return 0;
}
