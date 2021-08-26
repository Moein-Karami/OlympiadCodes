///Chefer


#include <bits/stdc++.h>

using namespace std;

main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        int ans=0;
        for(int j=2;j*j<=x;j++)
        {
            while(x%j==0)
            {
                ans++;
                x/=j;
            }
        }
        if(x>1)
            ans++;
        if(ans==2)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
