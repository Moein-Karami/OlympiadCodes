///DARK PROGRAMMER

#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
#define ll long long
int ans[1000000];
int main()
{
    long long int n,k;
    cin>>n;
    for(ll int j=1;j<=n;j++)
    {
        scanf ("%lld",&k);
        if (k==4)
        {
            printf ("YES \n");
            continue;
        }
        if(k==1)
        {
            printf ("NO \n");
            continue;
        }
        ll int q=sqrt(k);
        if(q*q!=k)
        {
             printf ("NO \n");
            continue ;
        }

        bool b=1;
        for(ll int i=2;i*i<=q;i++)
        {
            if(q%i==0)
            {
                b=0;al
                break;
            }
        }
        if(b)
             printf ("YES \n");
        else
             printf ("NO \n");
    }
    return 0;
}
