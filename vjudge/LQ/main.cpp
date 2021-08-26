///Chefer


#include <bits/stdc++.h>

using namespace std;
const int maxn=2e6;
int se[4*maxn],lazy[4*maxn],ts[4*maxn],tf[4*maxn],ls[4*maxn],lf[4*maxn];
string s;
void solve(int id,int L,int R)
{
    if(L+1==R)
    {
        if(s[L]=='4')
            lf[id]=1,tf[id]=1;
        else
            ls[id]=1,ts[id]=1;;
        return ;
    }
    int mid=(L+R)/2;
    solve(2*id,L,mid);
    solve(2*id+1,mid,R);
    int x=2*id,y=2*id+1;
    ts[id]=ts[x]+ts[y];
    tf[id]=tf[x]+tf[y];
    ls[id]=max(ls[x]+ts[y],max(tf[x]+ls[y],ts[x]+ts[y]));
    lf[id]=max(lf[x]+tf[y],max(ts[x]+lf[y],tf[x]+tf[y]));
}
void pakhsh(int id)
{
    int x=2*id,y=2*id+1;
    se[x]+=lazy[id];
    se[y]+=lazy[id];
    lazy[x]+=lazy[id];
    lazy[y]+=lazy[id];
    lazy[id]=0;
}
void add(int id,int L,int R,int l,int r)
{
    //cerr<<"L & R & ID : "<<L<<" "<<R<<" "<<id<<endl;
    pakhsh(id);
    if(l==L&&r==R)
    {
        se[id]++;
        lazy[id]++;
        return ;
    }
    int mid=(L+R)/2;
    int x=2*id,y=2*id+1;
    if(l<mid)
        add(2*id,L,mid,l,min(r,mid));
    if(r>mid)
        add(2*id+1,mid,R,max(mid,l),r);
    se[id]=0;
    if(se[x]%2==1&&se[y]%2==1)
    {
        tf[id]=ts[x]+ts[y];
        ts[id]=tf[x]+tf[y];
        lf[id]=max(ls[x]+ts[y],max(tf[x]+ls[y],ts[x]+ts[y]));
        ls[id]=max(lf[x]+tf[y],max(ts[x]+lf[y],tf[x]+tf[y]));
    }
    else if(se[x]%2==0&&se[y]%2==0)
    {
        ts[id]=ts[x]+ts[y];
        tf[id]=tf[x]+tf[y];
        ls[id]=max(ls[x]+ts[y],max(tf[x]+ls[y],ts[x]+ts[y]));
        lf[id]=max(lf[x]+tf[y],max(ts[x]+lf[y],tf[x]+tf[y]));
    }
    else if(se[x]%2==1&&se[y]%2==0)
    {
        ts[id]=tf[x]+ts[y];
        tf[id]=ts[x]+tf[y];
        ls[id]=max(lf[x]+ts[y],max(tf[x]+ts[y],ts[x]+ls[y]));
        lf[id]=max(ls[x]+tf[y],max(tf[x]+lf[y],ts[x]+tf[y]));
    }
    else
    {
        ts[id]=ts[x]+tf[y];
        tf[id]=tf[x]+ts[y];
        ls[id]=max(ls[x]+tf[y],max(ts[x]+tf[y],tf[x]+lf[y]));
        lf[id]=max(lf[x]+ts[y],max(ts[x]+ls[y],tf[x]+ts[y]));
    }
}
main()
{
    ios_base::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    cin>>s;
    solve(1,0,n);
    for(int o=0;o<q;o++)
    {
        string tp;
        cin>>tp;
        if(tp=="switch")
        {
            int l,r;
            cin>>l>>r;
            l--;
            add(1,0,n,l,r);
        }
        else
        {
            //cerr<<se[1]<<endl;
            if(se[1]%2==1)
                cout<<max(ts[1],lf[1])<<endl;
            else
                cout<<max(tf[1],ls[1])<<endl;
        }
    }
    return 0;
}
