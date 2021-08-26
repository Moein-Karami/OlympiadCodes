#include <bits/stdc++.h>

using namespace std;

int main()
{
    int cnt=0;
    for(int i=1;i<13892010;i++)
    {
        int n,t;
        n=i;
        t=0;
        while(n)
        {
            t=t*10+(n%10);
            n/=10;
        }
        if(t%i==0)
            cnt++;
    }
    cout<<cnt;
    return 0;
}
