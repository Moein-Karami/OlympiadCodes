#include <iostream>

using namespace std;
int a[1000000],cnt[11],ans;
int cnt1,cnt2,cnt3,cnt4,cnt5,cnt6,cnt7,cnt8,cnt9,cnt10;
int main()
{
    int m,n;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1)
            cnt1++;
        else if(a[i]==2)
            cnt2++;
        else if(a[i]==3)
            cnt3++;
        else if(a[i]==4)
            cnt4++;
        else if(a[i]==5)
            cnt5++;
        else if(a[i]==6)
            cnt6++;
        else if(a[i]==7)
            cnt7++;
        else if(a[i]==8)
            cnt8++;
        else if(a[i]==9)
            cnt9++;
        else if(a[i]==10)
            cnt10++;
    }
    cnt[1]=cnt1;
    cnt[2]=cnt[1]+cnt2;
    cnt[3]=cnt[2]+cnt3;
    cnt[4]=cnt[3]+cnt4;
    cnt[5]=cnt[4]+cnt5;
    cnt[6]=cnt[5]+cnt6;
    cnt[7]=cnt[6]+cnt7;
    cnt[8]=cnt[7]+cnt8;
    cnt[9]=cnt[8]+cnt9;
    cnt[10]=cnt[9]+cnt10;
    for(int i=1;i<=m;i++)
    {
        //cout<<"<<"<<i<<","<<cnt[i]<<">>"<<endl;
    }
    for(int i=1;i<=m;i++)
    {
        //cout<<"(("<<i<<","<<(cnt[i]-cnt[i-1])*((cnt[m]-cnt[i])+cnt[i-1])<<"))"<<endl;
        ans+=(cnt[i]-cnt[i-1])*((cnt[m]-cnt[i]));
    }
    cout<<ans;
    return 0;
}
