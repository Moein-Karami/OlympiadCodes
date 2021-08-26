///Chefer


#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> pip;
const int maxn=2e6;
int o[4*maxn],c[4*maxn],ans[4*maxn];
string s;
void solve(int id,int L,int R)
{
    if(L+1==R)
    {
        if(s[L]==')')
            c[id]++;
        else
            o[id]++;
        return ;
    }
    int mid=(L+R)/2;
    solve(2*id,L,mid);
    solve(2*id+1,mid,R);
    ans[id]=ans[2*id]+ans[2*id+1]+min(o[2*id],c[2*id+1]);
    o[id]=o[2*id+1]+max(0,o[2*id]-c[2*id+1]);
    c[id]=c[2*id]+max(0,c[2*id+1]-o[2*id]);
    return ;
}
pip say(int id,int L,int R,int l,int r)
{
    if(l==L&&r==R)
        return pip(ans[id],pii(o[id],c[id]));
    int mid=(L+R)/2;
    int ret=0;
    int o1=0,o2=0,c1=0,c2=0;
    pip ans;
    if(l<mid)
    {
        ans=say(2*id,L,mid,l,min(r,mid));
        ret+=ans.f;
        o1=ans.s.f;
        c1=ans.s.s;
    }
    if(r>mid)
    {
        ans=say(2*id+1,mid,R,max(l,mid),r);
        ret+=ans.f;
        o2=ans.s.f;
        c2=ans.s.s;
    }
    ret+=min(o1,c2);
    return pip(ret,pii(o2+max(0,o1-c2),c1+max(0,c2-o1)));
}
main()
{
    cin>>s;
    int q;
    cin>>q;
    solve(1,0,s.size());
    int l,r;
    for(int i=0;i<q;i++)
    {
        cin>>l>>r;
        l--;
        pip ans=say(1,0,s.size(),l,r);
        cout<<2*(ans.f)<<endl;
    }
    return 0;
}
