#include <bits/stdc++.h>

using namespace std;
int s1,s2;
int mod=10303;
int main()
{
    string s,t;
    s.push_back('K');
    s.push_back('1');
    s.push_back('0');
    s.push_back('1');
    s.push_back('1');
    s.push_back('0');
    s.push_back('0');
    for(int i=5;i<=1389;i++)
    {

        t.clear();
        t.push_back('K');
        for(int j=10;j>=0;j--)
        {
            if((1<<j)<=i)
            {
                    if(i&(1<<j))
                        t.push_back('1');
                    else
                        t.push_back('0');
            }
        }
        s2=t.size();
        s1=s.size();

        bool b=1;
        for(int j=s1-s2+1;j<s1;j++)
        {
            b=1;
            int tmp=1;
            for(int q=j;q<s1;q++)
            {
                if(s[q]!=t[tmp])
                {
                    b=0;
                }
                tmp++;
            }
            if(b)
            {
                for(int q=s1-j+1;q<s2;q++)
                {
                    s.push_back(t[q]);

                }
                j=s1+1;
            }
        }
        if(!b)
            for(int j=1;j<s2;j++)
                s.push_back(t[j]);
    }
    s1=s.size();
    for(int i=1;i<=s1;i++)
        cout<<s[i];
    cout<<endl;
    cout<<((s1-1)*1389)%mod;
    return 0;
}
