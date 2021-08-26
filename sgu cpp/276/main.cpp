#include <iostream>

using namespace std;

int main()
{
    int n , x , s;
    cin>>n>>x;
    s=x-n;
    if(s<=0)
        cout<<0;
    else if(s>0&&s<300)
        cout << 1;
    else if (s>=300 &&s<900 )
        cout<<2;
    else if (s>=900 && s<1800)
        cout<<3;
    else if (s>=1800)
        cout<<4;
    return 0;
}
