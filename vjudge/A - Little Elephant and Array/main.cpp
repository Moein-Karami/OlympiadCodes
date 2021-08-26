///Chefer


#include<bits/stdc++.h>
//#define int long long int
#define f first
#define s second
#define rand() rand()*rand()
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int>pip;
const int maxn=1e5+10;
int a[maxn];
pip q[maxn];
int tmp[maxn];
int s;
int ans;
int answer[maxn];
int cont [maxn];
bool cmp(pip A,pip B)
{
    if (A.f.f/s!=B.f.f/s)
        return A.f.f/s<B.f.f/s;
    return A.f.s>B.f.s;
}
int inf=1e9;
main()
{
    ios_base::sync_with_stdio(false);
    int n,m;
    //n=100000;m=100000;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];//a[i]=rand()%inf+1;
    s=sqrt(n);
    for(int i=1;i<=m;i++)
    {
        cin>>q[i].f.f>>q[i].f.s;
        //q[i].f.f=rand()%n;
        //q[i].f.s=rand()%n;
        //if(q[i].f.f>q[i].f.s)
            //swap(q[i].f.f,q[i].f.s);
        q[i].s=i;
    }

    sort(q+1,q+m+1,cmp);
    //for(int i=1;i<=m;i++)
        //cerr<<q[i].f.f<<" "<<q[i].f.s<<endl;

    int l=1;
    int r=n;

    for(int i=1;i<=n;i++)
    {
        if(a[i]<maxn)
        {
            if(cont[a[i]]==a[i])
                ans--;
            cont[a[i]]++;
            if(cont[a[i]]==a[i])
                ans++;
        }
    }

    for(int i=1;i<=m;i++)
    {
        if(q[i].f.f<l)
        {
            for(int j=l-1;j>=q[i].f.f;j--)
            {
                if(a[j]<maxn)
                {
                    if(cont[a[j]]==a[j])
                        ans--;
                    cont[a[j]]++;
                    if(cont[a[j]]==a[j])
                        ans++;
                }

            }
        }
        else if(q[i].f.f>l)
        {
            for(int j=l;j<q[i].f.f;j++)
            {
                if(a[j]<maxn)
                {
                    if(cont[a[j]]==a[j])
                        ans--;
                    cont[a[j]]--;
                    if(cont[a[j]]==a[j])
                        ans++;
                }

            }
        }
        l=q[i].f.f;
        if(q[i].f.s>r)
        {
            for(int j=r+1;j<=q[i].f.s;j++)
            {
                if(a[j]<maxn)
                {
                    if(cont[a[j]]==a[j])
                        ans--;
                    cont[a[j]]++;
                    if(cont[a[j]]==a[j])
                        ans++;
                }
            }
        }
        else if(q[i].f.s<r)
        {
            for(int j=r;j>q[i].f.s;j--)
            {
                if(a[j]<maxn)
                {
                    if(cont[a[j]]==a[j])
                        ans--;
                    cont[a[j]]--;
                    if(cont[a[j]]==a[j])
                        ans++;
                }
            }
        }
        r=q[i].f.s;
        answer[q[i].s]=ans;
    }
    for(int i=1;i<=m;i++)
        cout<<answer[i]<<"\n";
    return 0;
}
