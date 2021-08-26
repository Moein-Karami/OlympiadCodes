#include <iostream>
#define ll long long
using namespace std;

int main()
{
    int n;
    cin>>n;
    ll int sum=0;
    int a[n+1];
    ll int s[n+1];
    s[0]=0;
    a[0]=0;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        s[i]=s[i-1]+a[i];
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        cnt=0;
        if(n%i==0)
        {
            bool b=1;
            for(int j=i;j<=n;j+=i)
            {
                if(s[j]-s[j-i]==s[i])
                    cnt++;
                else
                {
                    b=0;
                    j=n+1;
                    break;
                }

            }
            if(b)
            {
            cout<<cnt;
            return 0;
            }
        }
    }
    return 0;
}
