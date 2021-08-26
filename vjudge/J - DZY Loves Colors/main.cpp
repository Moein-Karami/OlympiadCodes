///Chefer


#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn=1e5+10;
int  a[maxn];
int sa[maxn];
int seg[1000];
int sum[1000];
int ps[1000];
int s;
int tst[maxn];
int ptst[maxn];
main()
{
    ios_base::sync_with_stdio(false);
    ///
    while(1){
    //cerr<<"FUCK"<<endl;
    getchar();
    for(int i=0;i<maxn;i++)
    {
       a[i]=0;
       sa[i]=0;
       tst[i]=0;
       ptst[i]=0;
    }
    for(int i=0;i<1000;i++)
    {
        seg[i]=0;
        sum[i]=0;
        ps[i]=0;
    }
    ///
    int n,q;
    cin>>n>>q;
    ///
    //n=rand()%10+1;
    //q=rand()%15+1;
    //cerr<<n<<" "<<q<<endl;
    ///
    s=sqrt(n);
    for(int i=0;i<n;i++)
        a[i]=i+1,ptst[i]=i+1;
    for(int o=1;o<=q;o++)
    {
        ///
        //for(int i=0;i<(n/s+(n%s!=0));i++)
        //{
          //  cerr<<sum[i]<<" ";
        //}cerr<<endl;
        //for(int i=0;i<n;i++)
        //{
          //  cerr<<sa[i]<<" ";
        //}cerr<<endl;
        int tp,l,r;

        cin>>tp>>l>>r;
        //tp=rand()%2+1;
        //l=rand()%(n)+1;
        //r=rand()%(n)+1;
        //cerr<<"QUERI : "<<tp<<" "<<l<<" "<<r<<endl;
        //if(l>r)
          //  swap(l,r);
        l--;
        r--;
        int t1=l/s,t2=r/s;
        if(tp==1)
        {
            int x;
            cin>>x;
            //x=rand()%10LL+1;
            cerr<<x<<endl;
            ///
            for(int i=l;i<=r;i++)
                tst[i]+=fabs(ptst[i]-x),ptst[i]=x;
            if(seg[t1])
            {
                for(int i=s*t1;i<l;i++)
                    a[i]=seg[t1];
                for(int i=l;i<min(r+1,(t1+1)*s);i++)
                {
                    a[i]=x;
                    sa[i]+=fabs(x-seg[t1]);
                    sum[t1]+=fabs(seg[t1]-x);
                }

                seg[t1]=0;
            }
            else
            {
                for(int i=l;i<min(r+1,(t1+1)*s);i++)
                {
                    sum[t1]+=fabs(x-a[i]);
                    sa[i]+=fabs(x-a[i]);
                    a[i]=x;
                }

            }
            for(int i=t1+1;i<t2;i++)
            {
                if(seg[i])
                {
                    sum[i]+=s*fabs(x-seg[i]);
                    ps[i]+=fabs(x-seg[i]);
                    seg[i]=x;
                }
                else
                {
                    seg[i]=x;
                    for(int j=i*s;j<(i+1)*s;j++)
                    {
                        sum[i]+=fabs(x-a[j]);
                        sa[j]+=fabs(x-a[j]);
                        a[j]=x;
                    }
                }
            }
            if(t1!=t2)
            {
                if(seg[t2])
                {
                    for(int i=s*t2;i<=r;i++)
                    {
                        sum[t2]+=fabs(x-seg[t2]);
                        sa[i]+=fabs(x-seg[t2]);
                        a[i]=x;
                    }
                    for(int i=r+1;i<min((t2+1)*s,n);i++)
                        a[i]=seg[t2];
                    seg[t2]=0;
                }
                else
                {
                    for(int i=s*t2;i<=r;i++)
                    {
                        sa[i]+=fabs(x-a[i]);
                        sum[t2]+=fabs(x-a[i]);
                        a[i]=x;
                    }
                }
            }
        }
        else
        {
            int ans=0;
            for(int i=l;i<min(r+1,s*(t1+1));i++)
                ans+=sa[i]+ps[t1];
            for(int i=t1+1;i<t2;i++)
                ans+=sum[i];
            if(t2!=t1)
            {
                for(int i=t2*s;i<=r;i++)
                    ans+=sa[i]+ps[t2];
            }
            //cout<<ans<<"\n";
            int test=0;
            for(int i=l;i<=r;i++)
                test+=tst[i];
            if(ans!=test)
            {
                cerr<<"_______________________________________________"<<endl<<ans<<" "<<test<<" "<<o<<endl;
                getchar();
            }
        }
    }}
    return 0;
}
