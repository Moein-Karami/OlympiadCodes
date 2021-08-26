///Chefer


#include <bits/stdc++.h>
#define f first
#define s second
#define int long long int
using namespace std;
typedef pair<int,int> pii;
const int maxn=3e4;
int inf=1e9;
pii a[maxn];
int mid;
bool com(pii t1,pii t2)
{
    return t1.s<t2.s;
}
main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].f>>a[i].s;
        a[i].f+=inf;
        a[i].s+=inf;
    }
    int l=0,r=3*inf;
    while(l+1!=r)
    {
        mid=(l+r)/2;
        sort(a,a+n);
        int ans=0,tmp;
        int t1=0,t2=0;
        for(int i=1;i<n;i++)
        {
            if(a[i].f-mid>a[t1].f)
            {
                tmp=0;
                sort(a+t1,a+i,com);
                t2=t1;
                for(int j=t1;j<i;j++)
                {
                    if(a[j].s-mid>a[t2].s)
                    {
                        tmp++;
                        t2=j;
                    }
                }
                tmp+=(tmp==0);
                ans+=tmp;
                t1=i;
            }
        }
        if(ans>3)
            l=mid;
        else
            r=mid;
    }
    cout<<r;
    return 0;
}
