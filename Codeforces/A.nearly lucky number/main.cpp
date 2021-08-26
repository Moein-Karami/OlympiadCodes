#include <iostream>

using namespace std;
bool shans=1;
int main()
{
    long long unsigned int x , temp , z , cnt=0;
    cin >> x ;
    temp=x;
        while(x!=0)
    {
        temp=x%10;
        x/=10;
        if(temp==4||temp==7)
            cnt++;
    }
    if(cnt==4||cnt==7)
        cout<<"YES";
        else
        cout<<"NO";
    return 0;
}
