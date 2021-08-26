#include <bits/stdc++.h>
#define int long long int
using namespace std;
vector <int> tajzie;
int a[100];
main()
{
    int n,m;
    cin>>n>>m;
    for(int i=2;i*i<=n;i++)
    {
        while(n%i==0)
        {
            n/=i;
            tajzie.push_back(i);
        }
    }

    if(n>1)
        tajzie.push_back(n);
    int s=tajzie.size();
    for(int i=1;i<(1<<s);i++)
    {
        int t=0,tmp=1;
        for(int j=0;j<s;j++)
        {
            if((i&(1<<j)))
            {
                tmp*=tajzie[j];
                t++;
            }
        }
        a[t]+=(m/tmp);
    }
    int ans=0;

    for(int i=1;i<=33;i++)
    {
        if(i%2==1)
            ans+=a[i];
        else
            ans-=a[i];
    }
    cout<<m-ans;
    return 0;
}
