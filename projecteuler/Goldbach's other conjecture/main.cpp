#include <bits/stdc++.h>

using namespace std;
vector <int> prime;
bool p[100000];
bool check(int x)
{
    bool b=1;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)
            b=0;
        if(!b)
            i=x;
    }
    return b;
}

int main()
{
    for(int i=2;i<=10000;i++)
        if(check(i))
            prime.push_back(i),p[i]=1;
    for(int i=33;i<=1000000000;i+=2)
    {
        bool c=0;
        for(int j=0;j<prime.size();j++)
        {
            if(prime[j]>i||c==1)
            {
                j=100000;
                continue ;
            }
            int n,d;
            n=i-prime[j];
            n/=2;
            d=sqrt(n);
            if(d*d==n)
                c=1;
        }
        if(!c&&!p[i])
        {
            cout<<i<<endl;
            char c;
            cin>>c;
        }
    }
    return 0;
}
