#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn=1e6;
int st[4*maxn];
int a[maxn];
int tmp[maxn];
void add(int id,int l,int r,int L,int R,int val)
{
    int mid=(L+R)>>1;
    if(l==L&&r==R)
    {
        st[id]+=val;
        return ;
    }
    if(r>mid)
        add(2*id+1,max(mid,l),r,mid,R,val);
    if(l<mid)
        add(2*id+0,l,min(mid,r),L,mid,val);
}
int say(int id,int L,int R,int idx)
{
    int ret=0;
    ret+=st[id];
    int mid=(L+R)>>1;
    if(L+1==R)
    {
        return st[id];
    }
    if(idx<mid)
        ret+=say(2*id,L,mid,idx);
    else
        ret+=say(2*id+1,mid,R,idx);
    return ret;
}
main()
{
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        a[i]=rand()%n;
        ///cin>>a[i];
        tmp[i]=a[i];
        //cout<<a[i]<<" ";
    }//cout<<endl<<endl;
    int k;
    int l,r,val,id;
    for(int i=1;i<=q;i++)
    {
        k=rand()%2;
        //cout<<k<<endl;
        ///cin>>k;
        if(k==1)
        {
            l=rand()%n+1;
            r=rand()%n+1;
            val=rand()%n;
            if(l>r)
                swap(l,r);
            //cout<<l<<" "<<r<<" "<<val<<endl<<endl;
            ///cin>>l>>r>>val;

            l--;
            for(int j=l;j<r;j++)
                tmp[j]+=val;
            add(1,l,r,0,n,val);
        }
        else
        {
            id=rand()%n+1;
            ///cin>>id;
            //cout<<id<<endl<<endl;
            id--;
            if(say(1,0,n,id)+a[id]!=tmp[id])
            {
                //cout<<i<<" "<<id<<" "<<say(1,0,n,id)+a[id]<<" "<<tmp[id]<<" NO";
                return 0;
            }
            ///cout<<tmp[id]<<endl;
        }
    }
    cout<<"YES";
    return 0;
}
