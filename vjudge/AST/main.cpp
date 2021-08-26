///Chefer


#include <bits/stdc++.h>

using namespace std;
const int maxn=2e5;
int n,q;
string s;
int se[4*maxn][30];
int lazy[4*maxn][30];
map <char , int> mp;
map <int , char> mp2;
void init(int id,int L,int R,int idx,int tp)
{
    se[id][tp]++;
    if(L+1==R)
       return ;
    int mid=(L+R)/2;
    if(idx<mid)
        init(2*id,L,mid,idx,tp);
    else
        init(2*id+1,mid,R,idx,tp);
}
void pakhsh(int id,int tp,int L,int R)
{
    int mid=(L+R)/2;
    if(lazy[id][tp]==0)
        return;
    if(lazy[id][tp]==-1)
    {
        se[2*id][tp]=0;
        se[2*id+1][tp]=0;
        lazy[2*id][tp]=-1;
        lazy[2*id+1][tp]=-1;
    }
    else
    {
        se[2*id][tp]=mid-L;
        se[2*id+1][tp]=R-mid;
        lazy[2*id][tp]=1;
        lazy[2*id+1][tp]=1;
    }
    lazy[id][tp]=0;
}
int say(int id,int L,int R,int l,int r,int tp)
{
    pakhsh(id,tp,L,R);
    if(l==L&&r==R)
        return se[id][tp];

    int ret=0;
    int mid=(L+R)/2;
    if(l<mid)
        ret+=say(2*id,L,mid,l,min(r,mid),tp);
    if(r>mid)
        ret+=say(2*id+1,mid,R,max(mid,l),r,tp);
    return ret;
}
void add(int id,int L,int R,int l,int r,int tp,int val)
{
    if(l>=r)
        return ;
    pakhsh(id,tp,L,R);
    if(L==l&&r==R)
    {
        if(val==1)
            se[id][tp]=R-L;
        else
            se[id][tp]=0;
        lazy[id][tp]=val;
        return ;
    }
    int mid=(L+R)/2;
    if(l<mid)
        add(2*id,L,mid,l,min(r,mid),tp,val);
    if(r>mid)
        add(2*id+1,mid,R,max(l,mid),r,tp,val);
    se[id][tp]=se[2*id][tp]+se[2*id+1][tp];
}
main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>q;
    cin>>s;
    int cnt=0;
    for(char i='a';i<='z';i++)
    {
        cnt++;
        mp[i]=cnt;
        mp2[cnt]=i;
    }

    for(int i=0;i<n;i++)
    {
        init(1,0,n,i,mp[s[i]]);
    }
    for(int o=1;o<=q;o++)
    {
        int l,r,tp;
        cin>>l>>r>>tp;
        l--;
        int a[30]={0};
        for(int i=1;i<=26;i++)
        {
            a[i]=say(1,0,n,l,r,i);
            //cerr<<i<<" : "<<a[i]<<endl;
            add(1,0,n,l,r,i,-1);
        }
        int p=l;
        if(tp==1)
        {
            for(int i=1;i<=26;i++)
            {
                add(1,0,n,p,p+a[i],i,1);
                p+=a[i];
            }
        }
        else
        {
            for(int i=26;i>=1;i--)
            {
                add(1,0,n,p,p+a[i],i,1);
                p+=a[i];
            }
        }
        //for(int i=0;i<n;i++)
        //{
          //  for(int j=1;j<=26;j++)
            //{
              //  if(say(1,0,n,i,i+1,j)){
                //    cout<<mp2[j];break;}
            //}
        //}
        //cerr<<endl;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=26;j++)
        {
            if(say(1,0,n,i,i+1,j)){
                cout<<mp2[j];break;}
        }
    }
    return 0;
}
