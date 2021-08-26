#include <iostream>

using namespace std;

int main()
{
    long long unsigned int x,y ;
    cin>>x;
    y=(x/3)*2;
    if(x%3==2)
        y++;
    cout<<y;
}
