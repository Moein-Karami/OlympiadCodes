#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int inf =1e15;
main()
{
    set<int>se;
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        int x=inf;
        for(int j=i-1;j>=max(i-50,1LL);j--)
        {
            if((2*i-1-j)%((1LL<<(i-j))-1)==0)
            {
                x=min(x,(1LL<<(i-j))*((2*i-1-j)/((1LL<<(i-j))-1)));
            }
        }
        se.insert(x);
        cerr<<"I : "<<i<<" "<<x<<endl;
    }
    return 0;
}
