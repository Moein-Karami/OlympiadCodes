#include <iostream>
#include <string>
using namespace std;
string str;
int main()
{
    cin>>str;
    int h,m;
    h=((str[0]-48)*10)+(str[1]-48);
    m=((str[3]-48)*10)+(str[4]-48);
    int x;
    cin>>x;
    m+=x;
    int n=m/60;
    m=m%60;
    h+=n;
    h%=24;
    if(h/10==0&&m/10==0)
    cout<<0<<h<<":"<<0<<m;
    else if(h/10==0)
    cout<<0<<h<<":"<<m;
    else if (m/10==0)
    cout<<h<<":"<<0<<m;
    else
    cout<<h<<":"<<m;
    return 0;
}
