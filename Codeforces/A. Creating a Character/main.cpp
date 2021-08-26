#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(b+c<a)
        {
            cout<<c+1<<endl;
            continue;
        }
        a+=c;
        if(b>=a)
            cout<<0<<endl;
        else
        {
            int t=a-b;
            if((t%2)==1)
            {
                t=(t-1)/2;
                t++;
                cout<<t<<endl;
            }
            else
            {
                t=(t-2)/2;
                t++;
                cout<<t<<endl;
            }
        }
    }


}
