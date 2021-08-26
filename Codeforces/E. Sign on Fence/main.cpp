#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,pii> pip;
const int maxn=1e5+5;
int maxse[4*maxn],minse[4*maxn];
int ans[maxn];
pip a[maxn];
void changemin(int id,int L,int R,int idx,int val)
{
    if(L+1==R)
    {
        minse[id]=val;
        return ;
    }
    int mid=(L+R)/2;
    if(idx<mid)
        changemin(2*id,L,mid,idx,val);
    else
        changemin(2*id+1,mid,R,idx,val);

}
main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int h;
        cin>>h;
        changemin(1,1,n+1,i,h);
    }
    return 0;
}
