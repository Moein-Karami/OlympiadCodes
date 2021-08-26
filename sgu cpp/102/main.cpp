#include <iostream>

using namespace std;

bool x;

int main()
{
    int n , cnt=0 ;
    cin>>n;
    for (int i=1 ; i<n ; i++)
    {
        x=false;
        for (int j=2 ; j<=i ; j++)
        {
            if(n%j==0 && i%j==0)
            {
                x=true;
                j=i+1;
            }

        }
        if(x==false)
            cnt++;
    }
    if(n==1)
        cnt++;
    cout<<cnt;
    return 0;
}
