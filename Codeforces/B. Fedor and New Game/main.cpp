///DARK PROGRAMMER


#include <iostream>

using namespace std;
int a[3000];
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int ans=0;
    int k1=0;
    for(int i=1;i<=m+1;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
    {
        for(int t=0;t<n;t++)
            {
                if((((a[i])^(1<<t))>a[i])&&(((a[m+1])^(1<<t))<a[m+1]))
                    k1++;
                if((((a[i])^(1<<t))<a[i])&&(((a[m+1])^(1<<t))>a[m+1]))
                    k1++;
            }
        if(k1<=k)
            ans++;
        k1=0;
    }
    cout<<ans;
    return 0;
}
