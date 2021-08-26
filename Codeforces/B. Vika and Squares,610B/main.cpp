///I'm Chefer now ;)


#include <bits/stdc++.h>
#define int long long int
using namespace std;
int a[300000];
main()
{
    int n;
    cin>>n;
    int mini=1e9,maxi=0;
    for(int i=1;i<=n;i++)
        cin>>a[i],mini=min(mini,a[i]);
    int cnt,cnt2=0;
    int t=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==mini)
        {
            t=i;
            break;
        }
    }
    t--;
    for(int i=1;i<=n;i++)
    {
        cnt=0;
        if(a[i]==mini)
        {
            cnt2++;
            i++;
            while(i<=n&&a[i]!=mini)
            {
                cnt++;
                i++;
            }
            i--;
        }
        if(i==n)
            cnt+=t;
        maxi=max(cnt,maxi);
    }
    if(cnt2>1)
        cout<<mini*n+maxi;
    else
         cout<<n*(mini+1)-1;
    return 0;
}
