#include <iostream>

using namespace std;

int main()
{
    int n;
    for(int i=1;i<=1000;i++)
    {
        for(int j=1;j<=1000;j++)
        {
            for(int k=1;k<=1000;k++)
            {
                if((i*i)+(j*j)==k*k||(i*i)+(k*k)==j*j||(k*k)+(j*j)==i*i)
                {
                    if(i+j+k==1000)
                    {
                        cout<<"<<"<<i<<","<<j<<","<<k<<">>"<<endl;
                        cout<<i*j*k;
                        cin>>n;
                    }
                }
            }
        }
    }
    return 0;
}
