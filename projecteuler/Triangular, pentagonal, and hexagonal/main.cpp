#include <bits/stdc++.h>

using namespace std;
int p[100000],t[100000],h[100000];
int main()
{
    for(int i=1;i<=99990;i++)
    {
        t[i]=(i*(i-1))/2;
        p[i]=(i*(3*i-1))/2;
        h[i]=i*(2*i-1);
    }
    for(int i=1;i<=1000;i++)
    {
        for(int j=1;j<=1000;j++)
        {
            for(int w=1;w<=10000;w++)
            {
                if(h[i]==p[j]&&h[i]==t[w])
                {
                    cout<<i<<" "<<h[i]<<endl;
                    char c;
                    cin>>c;
                }
            }
        }
    }
    return 0;
}
