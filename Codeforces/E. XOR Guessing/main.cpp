///C


#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
main()
{
    cout<<"? ";
    for(int i=0;i<100;i++)
        cout<<i<<" ";
    cout<<endl;
    int x;
    cin>>x;
    cout<<"? ";
    for(int i=1;i<=100;i++)
        cout<<(i<<7)<<" ";
    cout<<endl;
    int y;
    cin>>y;
    int z=x^y;
    int t1,t2;
    for(int i=0;i<100;i++)
    {
        for(int j=1;j<=100;j++)
        {
            if((i^(j<<7))==z)
            {
                t1=i;
                t2=(j<<7);
                i=100;
                break;
            }
        }
    }
    cout<<"! "<<(x^t1)<<endl;
}
