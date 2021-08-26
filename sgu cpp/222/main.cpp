#include <iostream>

using namespace std;

int main()
{
    int n , k , z ;
    cin>>n>>k;
    int fac[n+1];
    fac[0]=1;
    for(int i=1 ; i<=n ; i++)
        fac[i]=fac[i-1]*i;
    if (k>n||k==0)
    {
        cout<<"0";
        return 0 ;
    }
    else
    {
        z=(fac[n]/(fac[k]*fac[n-k]))*(fac[n]/fac[n-k]);
    }
    cout << z;
    return 0;
}

