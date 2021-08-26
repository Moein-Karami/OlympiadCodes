///Chefer


#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn=1e5+5;
int se[5*maxn];
void add(int id,int L,int R,int l,int r,int val)
{
    if(l==L&&r==R)
    {
        se[id]+=val;
        return ;
    }
    int mid=(L+R)/2;
    if(l<mid)
        add(2*id,L,mid,l,min(r,mid),val);
    if(r>mid)
        add(2*id+1,mid,R,max(l,mid),r,val);
}
int say(int id,int L,int R,int idx)
{
    if(L+1==R)
        return se[id];
    int mid=(L+R)/2;
    if(idx<mid)
        return say(2*id,L,mid,idx);
    else
        return say(2*id+1,mid,R,idx);
}
main()
{
    ios_base::sync_with_stdio(false);
    int m;
    cin>>m;
    for(int o=1;o<=m;o++)
    {
        int n,u;
        cin>>n>>u;
        fill(se,se+5*maxn,0);
        int l,r,val;
        for(int i=1;i<=u;i++)
        {
            cin>>l>>r>>val;
            l--;
            add(1,0,n,l,r,val);
        }
        int q;
        cin>>q;
        int id;
        for(int i=1;i<=q;i++)
        {
            cin>>id;
            id--;
            cout<<say(1,0,n,id)<<endl;
        }
    }
    return 0;
}
