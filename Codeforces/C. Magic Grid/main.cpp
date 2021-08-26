///C


#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
int a[4][4]={8,9,1,13,3,12,7,5,0,2,4,11,6,10,15,14};
main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int t=16;
    n/=4;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<4;j++)
        {
            for(int k=0;k<n;k++)
            {
                for(int q=0;q<4;q++)
                {
                    cout<<a[j][q]+16*(i*n+k)<<" ";
                }
            }
            cout<<endl;
        }
    }
}
