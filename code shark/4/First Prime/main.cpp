#include <iostream>
#define int long long int
using namespace std;
const int maxn=1e9,mod=11969;
bool p[maxn];
main()
{
    for(int i=2;i<maxn;i++)
    {
        if(!p[i])
        {
            if(i>=mod*mod)
            {
                cout<<i;
                return 0;
            }
            for(int j=i*i;j<maxn;j+=i)
                p[j]=1;
        }
    }
    return 0;
}
