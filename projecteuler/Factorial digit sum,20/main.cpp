#include <iostream>

using namespace std;
long long int f[101];
int main()
{
    f[1]=1;
    for(int i=2;i<=100;i++)
    {
        f[i]=i*f[i-1];
    }
    bool b=1;
    while(b)
    {
        int x;
        cin>>x;
        cout<<f[x]<<endl;
    }

    return 0;
}
