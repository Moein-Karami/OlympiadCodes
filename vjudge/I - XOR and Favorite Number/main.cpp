///Chefer


#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<pair<int,int>,int> pii;
const int maxn=1e5+5;
int p[maxn];
int a[maxn];
pii q[maxn];
int ans[maxn];
int x;
int s;
int tmp[21*maxn][2];
int answer;
bool cmp(pii t1,pii t2)
{
    if(t1.f.f/s==t2.f.f/s)
        return t1.f.s<t2.f.s;
    return t1.f.f<t2.f.f;
}
main()
{
    ios_base::sync_with_stdio(false);
    //tmp[0][1]++;
    //tmp[0][0]++;
    int n,m,k;
    cin>>n>>m>>k;
    //n=6;
    //m=70;
    //k=rand()%7;
    //cerr<<n<<" "<<m<<" "<<k<<endl;
    s=sqrt(n);
    for(int i=1;i<=n;i++)
        cin>>a[i],p[i]=p[i-1]^a[i];
    //for(int i=1;i<=n;i++)
    //{
      //  a[i]=rand()%7;
    //    cerr<<a[i]<<" ";
  //      p[i]=p[i-1]^a[i];
//    }cerr<<endl;


    for(int i=1;i<=m;i++)
        cin>>q[i].f.f>>q[i].f.s,q[i].s=i;
    //for(int i=1;i<=m;i++)
    //{
        //q[i].f.f=rand()%n+1;
        //q[i].f.s=rand()%n+1;
        //if(q[i].f.f>q[i].f.s)
        //    swap(q[i].f.f,q[i].f.s);
      //  q[i].s=i;
    //}

    sort(q+1,q+m+1,cmp);
    int l=1,r=n;
    for(int i=1;i<=r;i++)
    {
        x^=a[i];
        answer+=tmp[x^k][1];
        tmp[x][1]++;
        if(x==k)
            answer++;
        //cerr<<"I : "<<i<<" "<<answer<<endl;
    }
    //cerr<<answer<<endl;
    for(int i=1;i<=m;i++)
    {
        //cerr<<q[i].f.f<<" "<<q[i].f.s<<endl;
        int nxtr=q[i].f.s;
        if(r>nxtr)
        {
            for(int j=r;j>nxtr;j--)
            {
                int xo=p[j]^p[l-1];
                xo^=k;
                answer-=tmp[xo^p[l-1]][1]-tmp[xo^p[l-1]][0];
                if(p[j]==(xo^p[l-1]))
                    answer++;
                if(xo==0)
                    answer--;
                tmp[p[j]][1]--;
                //cerr<<"J : "<<j<<" "<<answer<<endl;
            }
        }
        else if(r<nxtr)
        {
            for(int j=r+1;j<=nxtr;j++)
            {
                int xo=p[j]^p[l-1];
                xo^=k;
                tmp[p[j]][1]++;
                answer+=tmp[xo^p[l-1]][1]-tmp[xo^p[l-1]][0];
                if(xo==0)
                    answer++;
                if(p[j]==(xo^p[l-1]))
                    answer--;

            }
        }
        r=nxtr;
        int nxtl=q[i].f.f;
        if(l<nxtl)
        {
            for(int j=l;j<nxtl;j++)
            {
                answer-=tmp[k^p[j-1]][1]-tmp[k^p[j-1]][0];
                tmp[p[j]][0]++;
            }
        }
        else if(l>nxtl)
        {
            for(int j=l-1;j>=nxtl;j--)
            {
                tmp[p[j]][0]--;
                answer+=tmp[k^p[j-1]][1]-tmp[k^p[j-1]][0];
            }
        }
        l=nxtl;
        //cerr<<answer<<endl;
        //if(answer<0)
        //{
          //  getchar();
        //}
        ans[q[i].s]=answer;
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<"\n";
    return 0;
}
