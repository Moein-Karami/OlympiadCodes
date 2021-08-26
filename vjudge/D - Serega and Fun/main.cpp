///Chefer


#include<bits/stdc++.h>

using namespace std;
const int maxn=1e5+10;
int a[maxn];
queue <int> q[1000];
int cnt[400][maxn];
main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int s=sqrt(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    int m;
    cin>>m;
    for(int i=0;i<n/s+(n%s!=0);i++)
    {
        for(int j=min(n,(i+1)*s)-1;j>=i*s;j--)
        {
            cnt[i][a[j]]++;
            q[i].push(a[j]);
        }
    }
    int la=0;
    for(int o=1;o<=m;o++)
    {
        int tp,l,r;
        cin>>tp>>l>>r;
        l=(l+la-1)%n+1;
        r=(r+la-1)%n+1;
        l--;
        r--;
        if(l>r)
            swap(l,r);
        int t1=l/s;
        int t2=r/s;
        if(tp==1)
        {
            if(t1==t2)
            {
                int si=q[t1].size(),t[si];
                for(int i=si-1;i>=0;i--)
                {
                    t[i]=q[t1].front();
                    q[t1].pop();
                }
                l-=t1*s;
                r-=t1*s;
                for(int i=l;i<=r;i++)
                    swap(t[i],t[r]);
                for(int i=si-1;i>=0;i--)
                    q[t1].push(t[i]);
            }
            else
            {
                int p=q[t2-1].front();
                for(int i=t2-1;i>t1;i--)
                {
                    cnt[i][q[i].front()]--;
                    q[i].pop();
                    q[i].push(q[i-1].front());
                    cnt[i][q[i-1].front()]++;
                }
                cnt[t1][q[t1].front()]--;
                int si1=q[t1].size(),si2=q[t2].size(),tt1[si1],tt2[si2];
                l-=t1*s;
                r-=t2*s;
                for(int i=si1-1;i>=0;i--)
                {
                    tt1[i]=q[t1].front();
                    q[t1].pop();
                }
                for(int i=si2-1;i>=0;i--)
                {
                    tt2[i]=q[t2].front();
                    q[t2].pop();
                }
                //for(int i=0;i<2;i++)
                  //  cerr<<tt1[i]<<" ";
                //cerr<<endl;
                //for(int i=0;i<2;i++)
                  //  cerr<<tt2[i]<<" ";
                //cerr<<endl;
                cnt[t1][tt2[r]]++;
                cnt[t2][tt2[r]]--;
                cnt[t2][p]++;
                for(int i=l;i<si1;i++)
                    swap(tt1[i],tt2[r]);
                swap(p,tt2[r]);
                for(int i=0;i<=r;i++)
                    swap(tt2[i],tt2[r]);

                for(int i=si1-1;i>=0;i--)
                    q[t1].push(tt1[i]);

                for(int i=si2-1;i>=0;i--)
                    q[t2].push(tt2[i]);
            }
        }
        else
        {
            int k;
            cin>>k;
            k=(k+la-1)%n+1;
            int ans=0;
            for(int i=t1+1;i<t2;i++)
                ans+=cnt[i][k];
            l-=s*t1;
            r-=s*t2;
            int si1=q[t1].size(),tt1[si1];
            for(int i=si1-1;i>=0;i--)
            {
                tt1[i]=q[t1].front();
                q[t1].pop();
            }
            int si2=q[t2].size(),tt2[si2];
            for(int i=si2-1;i>=0;i--)
            {
                tt2[i]=q[t2].front();
                q[t2].pop();
            }
            if(t1==t2)
            {
                for(int i=l;i<=r;i++)
                    if(tt1[i]==k)
                        ans++;
                for(int i=si1-1;i>=0;i--)
                    q[t1].push(tt1[i]);
            }
            else
            {
                for(int i=l;i<si1;i++)
                    if(tt1[i]==k)
                        ans++;
                for(int i=0;i<=r;i++)
                    if((tt2[i]==k))
                        ans++;
                for(int i=si1-1;i>=0;i--)
                    q[t1].push(tt1[i]);
                for(int i=si2-1;i>=0;i--)
                    q[t2].push(tt2[i]);
            }
            cout<<ans<<"\n";
            la=ans;
        }
    }
    return 0;
}
