///DARK PROGRAMMER


#include <iostream>
#include <vector>

using namespace std;
int ans[1000000];
vector <int> aval;
int main()
{
    int n;
    cin>>n;
    if(n==1)
    {
            cout<<1;
            return 0;
    }

    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;

        for(int j=2;j*j<=x;j++)
        {
            if(x%j==0)
            {
                ans[j]++;
            }
            while(x%j==0)
                x/=j;
        }
        if(x!=1)
            ans[x]++;
    }

    int maxi=1;
    for(int i=0;i<100000;i++)
        maxi=max(ans[i],maxi);
    cout<<maxi;
    return 0;
}
