#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=10211;
int f[1005000];
int gcd(int x,int y)
{
    while(x&&y)
    {
        if(x<y)
            swap(x,y);
        x%=y;
    }
    return max(x,y);
}
main()
{
    int n;
    cin>>n;
    /*int x=13;
    f[4]=x;
    for(int i=5;i<=1000000;i++)
    {
        ///cerr<<"I : "<<i<<" "<<x<<endl;
        x=x+gcd(i,x);
        f[i]=x;
        if(f[i]!=f[i-1]+1)
        {
            cerr<<"FIND : "<<i<<endl;
            getchar();
        }
        cerr<<"I : "<<i<<" "<<x<<endl;
    }
    cout<<x%mod;//*/
    int p=4,x=13;
    while(p<n)
    {
        //cerr<<"P : "<<p<<endl;
        //getchar();
        bool b=0;
        for(int i=p+1;i<=p+5000000;i++)
        {
            x+=gcd(i,x);
            if(i==n||x==3*i)
            {
                p=i;
                b=1;
                break;
            }
        }
        if(b)
            continue;
        p+=5000000;
        int t=x-2*p-1;
        p+=t;
        x=3*p;
        x=2*p;
        p--;
        if(p>n)
            break;
        p++;
        x=3*p;
    }
    if(p>n)
        x-=p-n;
    cout<<x%mod;
    return 0;
}
