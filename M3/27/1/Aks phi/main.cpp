#include <iostream>
#define int long long int
using namespace std;
main()
{
    int n;
    cin>>n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            cerr<<i<<" ";
            int cnt=0;
            while(n%i==0)
                n/=i,cnt++;
            cerr<<cnt<<endl;
        }
    }
    if(n>1)
        cerr<<n<<" "<<1;
    return 0;
}
