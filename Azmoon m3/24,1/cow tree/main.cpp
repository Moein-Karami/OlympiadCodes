#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=10631;
int mindp[1000010];
int t[1000010] ;
int maxi;
int solve(int x,int y)
{
    int ret=0;
    ret=y-t[x-1];

}
main()
{
    int x;
    cin>>x;
    for(int i=1;i<=x;i++)
        t[x]=(t[x-1]*2)%mod;
    mindp[1]=2;
    for(int i=2;i<=x;i++)
    {
        mindp[i]=(mindp[i-1]+(t[i]-1)+((t[i]-1)*t[i-2]))%mod;
    }
    maxi=t[x]-1;
    maxi+=2*solve(1,t[x]-1)+t[x]-1;
    return 0;
}
