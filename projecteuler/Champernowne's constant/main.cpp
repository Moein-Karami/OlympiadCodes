#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ans=1;
    int k=0,tmp=0,t;
    for(int i=1;i<=1000000;i++)
    {
        tmp=i;
        while(tmp)
        {
            k++;
            if(k==1||k==10||k==100||k==1000||k==10000||k==100000||k==1000000)
            {
                cout<<tmp<<" "<<i<<endl;

            }
            tmp/=10;
        }
    }
    cout<<ans;
    return 0;
}
