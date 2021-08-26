///Chefer


#include <bits/stdc++.h>

using namespace std;

main()
{
    int n,k,t=0,tmp,ans=0;
    cin>>n>>k;
    while(k>0&&n)
    {
        ans++;
        n--;
        cin>>tmp;
        t+=tmp;
        if(t<=8)
        {
            k-=t;
            t=0;
        }
        else
        {
            k-=8;
            t-=8;
        }
    }
    if(k>0)
        cout<<-1;
    else
        cout<<ans;
    return 0;
}
