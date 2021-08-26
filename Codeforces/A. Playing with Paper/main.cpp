///DARK PROGRAMMER


#include <iostream>

using namespace std;

int main()
{
    long long int a,b;
    cin>>a>>b;
    if(a==b)
    {
        cout<<1;
        return 0;
    }
    long long int cnt=0;
    while(a!=b)
    {

        long long int maxi=max(a,b),mini=min(a,b);
        cnt=cnt+(maxi/mini);
        b=mini;
        a=(maxi%mini);
        if(a==0)
            a=b;
        //cout<<a<<" "<<b<<endl;
    }
    cout<<cnt;
    return 0;
}
