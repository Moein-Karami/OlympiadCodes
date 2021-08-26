#include <iostream>

using namespace std;

int main()
{
    int a,b,c,ans=1;
    cin>>a>>b>>c;
    for(int i=c;i>=1;i--)
    {
        ans++;
        if(ans%2==0)
        {
            for(int j=i;j>=1;j--)
            {
                if(i%j==0&&a%j==0)
                {
                    i-=j;
                    i++;
                    j=0;
                }
            }
        }
        else
        {
           for(int j=i;j>=1;j--)
            {
                if(i%j==0&&b%j==0)
                {
                    i-=j;
                    i++;
                    j=0;
                }
            }
        }
        //cout<<i<<" ";
    }
    //cout<<endl;
    if(ans%2==0)
        cout<<0;
    else
        cout<<1;

    return 0;
}
