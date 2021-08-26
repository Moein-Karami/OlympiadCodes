#include <iostream>

using namespace std;

int main()
{
    int ans=0,maxi=0,p;
    for(int r=1;r<=1000;r++)
    {
        ans=0;
        for(int i=1;i<=r;i++)
        {
            for(int j=i;j<=r-i;j++)
            {
                for(int q=j;q<=r-i-j;q++)
                {
                    if(i+j+q==r&&i*i+j*j==q*q&&i+j>q)
                        ans++;
                }
            }
        }
        if(ans>maxi)
        {
            maxi=ans;
            p=r;
        }
    }

    cout<<p;
    return 0;
}
