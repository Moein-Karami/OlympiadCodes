#include <iostream>

using namespace std;
int a[200],ans;
bool b[200],b2[10];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        b[i]=true;
        cin>>a[i];
        while(a[i]!=0)
        {
            b2[a[i]%10]=true;
            a[i]/=10;

        }
        if(b[i])
        ans++;
        for(int i=0;i<=k;i++)
        {
            if(b2[i]==0)
            {
            ans--;
            i=k+1;
            }
        }
        for(int i=0;i<=9;i++)
        {
            b2[i]=0;
        }

    }
    cout<<ans;
    return 0;
}
