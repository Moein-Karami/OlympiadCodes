#include <bits/stdc++.h>

using namespace std;
vector <int> fibo;
int main()
{
    fibo.push_back(1);
    fibo.push_back(1);
    fibo.push_back(1);
    int i=2;
    while(fibo[i]<=1000000)
    {
        i++;
        fibo.push_back(fibo[i-1]+fibo[i-2]);
    }
    int ans=0;
    int s=fibo.size();
    for(int j=100000;j<=999999;j++)
    {
        bool b=1;
        for(int q=3;q<s;q++)
        {
            if(fibo[q]<=j&&j%fibo[q]==0)
            {
                b=0;
            }
        }
        if(b)
            ans++;
    }
    double r=ans,f=900000,g=100,d=10099;
    cout<<(r/f)*g*d;
    return 0;
}
