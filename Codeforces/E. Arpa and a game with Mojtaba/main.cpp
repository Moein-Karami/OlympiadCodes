///Chefer


#include <bits/stdc++.h>
#define int long long int
using namespace std;
map <string,int> dp;
map <int,char> mp;
int a[1000];
int ans;
int maxi;
bool game[100];
main()
{
    for(char i='0';i<50;i++)
        mp[i-'0']=i;
    int n;
    cin>>n;
    set<int>:: iterator x;
    int tmp;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxi=max(maxi,a[i]);
    }
    for(int i=2;i*i<=maxi;i++)
    {
        set <int> se;
        bool b=0;
        for(int j=0;j<50;j++)
            game[j]=0;
        for(int j=1;j<=n;j++)
        {
            int cnt=0;
            while(a[j]%i==0)
            {
                cnt++;
                a[j]/=i;
            }
            if(cnt&&!game[cnt]){
                se.insert(cnt);b=1;game[cnt]=1;}
        }
        int mark=1;
        bool c=0;
        int y=0,t=0;
        while(se.size())
        {
            mark%=2;
            x=se.begin();
            tmp=*x;
            se.erase(tmp);
            tmp-=y;
            if(tmp>1){
                ans+=2-mark;
                c=1;
                break;}
            y+=tmp;
            mark++;
        }
        if(b&&!c)
        {

            mark=1-mark;
            ans+=2-mark;
        }
    }
    ///
    for(int i=1;i<=n;i++)
    {
        if(a[i]>1)
        {
            for(int j=0;j<50;j++)
                game[j]=0;
            set <int> se;
            bool b=0;
            int k=a[i];
            for(int j=1;j<=n;j++)
            {
                int cnt=0;
                while(a[j]%k==0)
                {
                    cnt++;
                    a[j]/=k;
                }
                if(cnt&&!game[cnt]){
                se.insert(cnt);b=1;game[cnt]=1;}
            }
            int mark=1;
            bool c=0;
            int y=0;
            while(se.size())
            {
                mark%=2;
                x=se.begin();
                tmp=*x;
                se.erase(tmp);
                tmp-=y;
                if(tmp>1){
                    ans+=2-mark;
                    c=1;
                    break;}
                y+=tmp;
                mark++;
            }
            if(b&&!c)
            {
                mark=1-mark;
                ans+=2-mark;
            }
        }
    }
    if(ans%2==1)
        cout<<"Mojtaba";
    else
        cout<<"Arpa";
    return 0;
}
