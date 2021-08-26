#include <iostream>
#include <string>

using namespace std;
int p[1000000+100];
int str[1000000+10];
int fa[1000000];
pair<int,int> temp[100000+10];
int main()
{
    int temp3;
    int x;
    cin>>x;
    string st;
    cin>> st;
    int n=0;
    n=st.length();
    for(int i=0 ;i<n;i++)
        str[i]=st[i]-48;
    if(x!=0)
    {
    p[0]=0;
    for(int i=1;i<=n;i++)
    {

        p[i]=p[i-1]+str[i-1];
    }

    p[0]=0;
    p[-1]=-1;
    int cnt=0,cnt2=0 ;
    for(int i=n;i>=0;i--)
    {
        if(p[i]==p[i-1])
        {
            cnt++;
        }
        else
        {
            cnt++;
            temp[cnt2].first=p[i];
            temp[cnt2].second=cnt;
            cnt=0;
            cnt2++;
        }
    }
    cnt2--;
    int pars,ans=0;
    for(int i=0;i<=cnt2;i++)
    {
        for(int j=i;j<=cnt2;j++)
        {
            if(temp[i].first-temp[j].first==x)
            {
                ans+=temp[i].second*temp[j].second;
                j=cnt2+1;
            }
        }
    }
    cout<<ans;
    }
    else
    {
        int ans=0;
        int cnt=0;
        int cnt2=0;
        for(int i=0;i<=n;i++)
        {
            if(i==n)
            {
                fa[cnt2]=cnt;
                cnt=0;
            }
            else if(str[i]==0)
            {
                cnt++;
            }
            else if(str[i]==1)
            {
                fa[cnt2]=cnt;
                cnt=0;
                cnt2++;
            }

        }
        for(int i=0;i<=cnt2;i++)
        {
            ans+=(fa[i]*(fa[i]-1)/2)+fa[i];
        }
        cout<<ans;
    }
    return 0;
}
