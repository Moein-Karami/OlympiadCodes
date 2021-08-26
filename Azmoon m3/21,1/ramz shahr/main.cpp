#include <bits/stdc++.h>
#define int long long int

using namespace std;

int mod=10487;
int process(long long x)
{
    int y = 0;
    if (x % 2)
        return -1;
    for (x = x / 2; x > 1; x = x / 2)
    {
        y*=2;
        y+=1-(x%2);
    }
    return y;
}
main()
{
    cout<<mod*mod;
    cout<<endl;
    for(int i=2;i<=10000000;i+=2)
    {
        for(int j=30;j>=0;j--)
        {
            if((1<<j)<=i)
            {
                if((1<<j)&i)
                    cout<<1;
                else
                    cout<<0;
            }
        }
        cout<<"  "<<i<<" "<<process(i)<<endl;
    }
    return 0;
}
