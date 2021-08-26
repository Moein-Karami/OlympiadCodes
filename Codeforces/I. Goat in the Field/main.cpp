///Chefer


#include <bits/stdc++.h>

using namespace std;
const int maxn=1e4+4;
string s[maxn];
int ans[maxn];
main()
{
    int x,y;
    cin>>x>>y;
    string t;
    cin>>t;
    int n;
    cin>>n;
    int xt,yt,tmp;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        cin>>xt>>yt;
        if(t[0]=='L'||t[0]=='R')
        {
            ans[i]+=fabs(y-yt)/2;
            int o=(fabs(y-yt));
            if(o%2==1)
                ans[i]++;
            tmp=x+ans[i];
            if(tmp>=xt)
            {
                if(t[0]=='R')
                    ans[i]+=tmp-xt;
                else
                    ans[i]+=(tmp-xt)/3+((tmp-xt)%3!=0);
            }
            else if(tmp<xt)
            {
                if(t[0]=='L')
                    ans[i]+=xt-tmp;
                else
                    ans[i]+=(xt-tmp)/3+((xt-tmp)%3!=0);
            }
        }
        else
        {
            int o=fabs(x-xt);
            o%=2;
            ans[i]+=fabs(x-xt)/2+o;
            tmp=y+ans[i];
            if(tmp>=yt)
            {
                if(t[0]=='U')
                    ans[i]+=tmp-yt;
                else
                    ans[i]+=(tmp-yt)/3+((tmp-yt)%3!=0);
            }
            else if(tmp<yt)
            {
                if(t[0]=='D')
                    ans[i]+=yt-tmp;
                else
                    ans[i]+=(yt-tmp)/3+((yt-tmp)%3!=0);
            }
        }
    }
    int ret=1;
    for(int i=1;i<=n;i++)
    {
        if(ans[i]<ans[ret])
            ret=i;
        cerr<<ans[i]<<endl;
    }
    cout<<s[ret];
    return 0;
}
