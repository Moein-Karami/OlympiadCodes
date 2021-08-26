#include <bits/stdc++.h>

using namespace std;
int mod=10303;
int main()
{
    string s;
    s.push_back('L');
    for(int i=2;i<=1389;i++)
    {
        bool b=1;
        for(int j=2;j*j<=i;j++)
        {
            if(i%j==0)
            {
                b=0;
                break;
            }
        }
        if(b)
            s.push_back('R');
        else
            s.push_back('L');
    }
    bool b=1;
    int t=0;
    while(b)
    {
        t++;
        b=0;
        for(int i=0;i<1388;i++)
        {
            if(s[i]=='R'&&s[i+1]=='L')
            {
                i++;
                b=1;
                s[i-1]='L';
                s[i]='R';
            }
        }
    }
    t--;
    cout<<(t+t*t+t*t*t)%mod;
    return 0;
}
