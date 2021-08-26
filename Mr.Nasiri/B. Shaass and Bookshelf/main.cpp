#include <iostream>
#include <algorithm>
#define f first
#define s second
using namespace std;

pair<int,int> dp1[200];
pair<int,int>dp2[200];
pair<int,int>tmp1[200];
pair<int,int>tmp2[200];

int p1[200],p2[200],p3[200],p4[200];
int main()
{
    int n,x,cnt1=1,cnt2=1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
       cin>>x;
       if(x==1)
       {
           dp1[cnt1].s=1;
           cin>>dp1[cnt1].f;
           cnt1++;
       }
       else
       {
          dp2[cnt2].s=2;
          cin>>dp2[cnt2].f;
          cnt2++;
       }
    }
    sort(dp1,dp1+cnt1);
    sort(dp2,dp2+cnt2);
    int cnt=1;
    for(int i=cnt1-1;i>=1;i--)
    {
        tmp1[cnt].f=dp1[i].f;
        tmp1[cnt].s=dp1[i].s;
        cnt++;
        ///
        //cout<<"<<"<<tmp1[cnt-1].s<<","<<tmp1[cnt-1].f<<">>";
        ///
    }
    //cout<<endl;
    cnt=1;
    for(int i=cnt2-1;i>=1;i--)
    {
        tmp2[cnt].f=dp2[i].f;
        tmp2[cnt].s=dp2[i].s;
        cnt++;
        ///
        //cout<<"<<"<<tmp2[cnt-1].s<<","<<tmp2[cnt-1].f<<">>";
        ///
    }
    //cout<<endl;
    //cout<<endl;
    for(int i=1;i<cnt1;i++)
    {
        p2[i]=p2[i-1]+tmp1[i].s;
        p1[i]=p1[i-1]+tmp1[i].f;
        //cout<<"(("<<p2[i]<<","<<p1[i]<<"))";
    }
    //cout<<endl;
    for(int i=1;i<cnt2;i++)
    {
        p4[i]=p4[i-1]+tmp2[i].s;
        p3[i]=p3[i-1]+tmp2[i].f;
        //cout<<"(("<<p4[i]<<","<<p3[i]<<"))";
    }
    //cout<<endl;
    int ans=1e9;
    for(int i=0;i<cnt1;i++)
    {
        for(int j=0;j<cnt2;j++)
        {
            if(p2[i]+p4[j]>=p1[cnt1-1]-p1[i]+p3[cnt2-1]-p3[j])
            {
                if(ans>p2[i]+p4[j])
                ans=p2[i]+p4[j];
            }

        }

    }
    cout<<ans;
    return 0;
}
