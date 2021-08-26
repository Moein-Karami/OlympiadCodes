#include <iostream>

using namespace std;
pair<int,int> q[100000];
long long int f[100000];
long long int p[100000];
int mod=1e9 +7;
int main()
{
    int t,k;
    cin>>t>>k;
    for(int i=1;i<=t;i++)
    {
        cin>>q[i].first>>q[i].second;
    }
    for(int i=0;i<k;i++)
        f[i]=1;
    f[k]=2;
    for (int i=k+1;i<=1e5;i++)
    {
        f[i]=(f[i-1]+f[i-k])%mod;
    }
    for(int i=1;i<=1e5;i++)
    {
        p[i]=(p[i-1]+f[i])%mod;
    }
    for(int i=1;i<=t;i++)
    {
        cout<<(p[q[i].second]-p[q[i].first]+f[q[i].first]+mod)%mod;
        cout<<endl;
    }

    return 0;
}
