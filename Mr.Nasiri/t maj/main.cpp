#include <iostream>

using namespace std;
bool a[10000];
int n,k,cnt,cnt2,ans;
void chap(int);
int main()
{

    cin>>n>>k;
    int x=0;
    chap(0);
    cout<<ans<<endl;

    return 0;
}
void chap(int x)
{
    if(cnt2>k||n-x+1+cnt2<k)
        return;
    if(n==x&&cnt2<k)
        return;
    if(x==n)
    {
        ans++;
   // cout<<cnt2<<"@@@@";
        cnt=0;
        for(int i=0;i<n;i++)
            if(a[i])
                cnt++;
        if(cnt==k)
        {
            for(int i=0;i<n;i++)
                    if(a[i])
                    cout<<i<<" ";
                cout<<endl;
        }
        return;
    }
    a[x]=1;
    cnt2++;
    chap(x+1);
    a[x]=0;
    cnt2--;
    chap(x+1);
}
