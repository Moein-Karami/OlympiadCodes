///Chefer


#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn=2e5;
int se[4*maxn][2];
int ans;
int IN;
int a[maxn];
int t[maxn];
int tree[maxn];
int p1,p2;
map <int,int> mp;
//void add(int id,int L,int R,int val,int idx,int tp)
//{
  //  se[id][tp]+=val;
    //if(L+1==R)
      //  return ;
    //int mid=(L+R)/2;
    //if(idx<mid)
      //  add(2*id,L,mid,val,idx,tp);
    //else
      //  add(2*id+1,mid,R,val,idx,tp);
//}
//int say(int id,int L,int R,int l,int r,int tp)
//{
    //cerr<<"L & R & l & r : "<<L<<" "<<R<<" "<<l<<" "<<r<<endl;
  //  if(l>=r)
    //    return 0;
    //if(l==L&&r==R)
      //  return se[id][tp];
    //int mid=(L+R)/2;
    //int ret=0;
    //if(l<mid)
      //  ret+=say(2*id,L,mid,l,min(mid,r),tp);
    //if(r>mid)
      //  ret+=say(2*id+1,mid,R,max(mid,l),r,tp);
    //return ret;
//}
void update(int idx ,int val){
    while (idx <= MaxVal){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}
int read(int idx){
    int sum = 0;
    while (idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
main()
{
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    p1=1;
    p2=n+1;
    for(int i=1;i<=n;i++)
        cin>>a[i],t[i]=a[i];
    sort(t+1,t+n+1);
    int cnt=1;
    for(int i=1;i<=n;i++)
        if(!mp[t[i]])
            mp[t[i]]=cnt,cnt++;
    for(int i=1;i<=n;i++)
        a[i]=mp[a[i]];
    ///add(1,0,n,1,a[p1],0);
    update(a[p1],1);
    for(int i=n;i>=1;i--)
    {
        if(IN>k)
            break;
        p2=i;

        ///IN+=say(1,0,n,a[i]+1,n,0);//cerr<<"DONE"<<endl;
        IN+=read(n)-read(a[i]);
        ///IN+=say(1,0,n,0,a[i],1);
        IN+=read(a[i]-1);
        add(1,0,n,1,a[i],1);
    }

    if(IN<=k)
    {
        cout<<(n*(n-1))/2;
        return 0;
    }
    ///IN-=say(1,0,n,a[p2]+1,n,0);
    IN-=read(n-1)-read(a[p2]);
    ///IN-=say(1,0,n,0,a[p2],1);
    IN-=read(a[p2]-1);
    ///add(1,0,n,-1,a[p2],1);
    update(a[p2],-1);
    p2++;
    ans+=n-p2;
    for(int i=1;i<(n-1);i++)
    {
        p1=i;
        ///IN+=say(1,0,n,a[i]+1,n,0);
        IN+=read(n-1)-read(a[i]);
        IN+=say(1,0,n,0,a[i],1);
        add(1,0,n,1,a[i],0);
        for(int j=p2;j<n;j++)
        {
            if(IN<=k)
                break;
            IN-=say(1,0,n,a[p2]+1,n,0);
            IN-=say(1,0,n,0,a[p2],1);
            add(1,0,n,-1,a[p2],1);
            p2++;
        }
        if(IN>k)
            break;
        ans+=n-p2;
    }
    cout<<ans;
    return 0;
}
