///DARK PROGRAMMER



#include <bits/stdc++.h>

using namespace std;
string s[51],ans[51],a[51],antar[51];
int main()
{
    int n,k,tmp=0;
    cin>>n>>k;
    s[1]='A';
    int cnt=2;
    antar[1]='A';

    for(char i='B';i<='Z';i++)
    {
        s[cnt]=i;
        cnt++;
    }
    for(int i=2;i<=50;i++)
    {
        if(antar[i-1].size()<10)
            antar[i]=antar[i-1],antar[i]+='a';
        else
            antar[i]=s[i/10+2];
    }
    for(int i=1;i<=n-k+1;i++)
        cin>>a[i];
    if(a[1][0]=='N')
    {
        ans[1]=s[1];
        ans[1]+='r';
        ans[2]=ans[1];
        tmp+=2;
    }
    else
    {
        ans[1]=s[1];
        for(int i=2;i<=k;i++)
        {
            if(s[i-1].size()<10)
                ans[i]=antar[i];
            else
                ans[i]=s[i/10+2];
        }
        tmp+=k;
    }
    for(int i=2;i<=n-k+1;i++)
    {
        if(a[i][0]=='N')
        {
            int t=0;
            for(int j=tmp+1;j<i+k;j++)
            {
                if(ans[j-1].size()<10)
                    ans[j]=antar[j];
                else
                {
                    ans[j]=s[j/10+3];
                }

                t++;
            }
            tmp+=t;
            ans[tmp]=ans[i];
        }
        else
        {
            int t=0;
            for(int j=tmp+1;j<i+k;j++)
            {
                if(ans[j-1].size()<10)
                    ans[j]=antar[j];
                else
                {
                    ans[j]=s[j/10+3];
                }

                t++;
            }
            tmp+=t;
        }
    }
    if(tmp<n)
    {
        for(int j=tmp+1;j<=n;j++)
            {
                if(ans[j-1].size()<10)
                    ans[j]=antar[j];
                else
                {
                    ans[j]=s[j/10+3];
                }
            }
        tmp=n;
    }
    for(int i=1;i<=tmp;i++)
        cout<<ans[i]<<" ";
    return 0;
}
