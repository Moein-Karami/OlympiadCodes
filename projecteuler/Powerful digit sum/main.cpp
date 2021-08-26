#include <iostream>

using namespace std;
int a[202];
int main()
{
    int ans=0,t=0;
    for(int i=1;i<100;i++)
    {
        for(int j=1;j<100;j++)
        {
            for(int q=0;q<=201;q++)
                a[q]=0;
            a[1]=i;
            for(int q=2;q<=j;q++)
            {
                for(int w=1;w<=201;w++)
                    a[w]*=i;
                for(int w=1;w<=201;w++)
                {
                    a[w+1]+=a[w]/10;
                    a[w]%=10;
                }
            }
            t=0;
        for(int q=1;q<=201;q++)
            t+=a[q];
        ans=max(ans,t);
        }

    }
    cout<<ans;
    return 0;
}
