///Chefer



#include <bits/stdc++.h>
#define int long long int

using namespace std;

main()
{
    char t1,t2;
    int x,y;
    cin>>t1>>t2;
    int n;
    cin>>n;
    if(t1=='^')
        x=0;
    else if(t1=='>')
        x=1;
    else if(t1=='v')
        x=2;
    else if(t1=='<')
        x=3;
    if(t2=='^')
        y=0;
    else if(t2=='>')
        y=1;
    else if(t2=='v')
        y=2;
    else if(t2=='<')
        y=3;
    n%=4;
    if((x+n)%4==y&&(x-n+1000000000)%4==y)
        cout<<"undefined";
    else if((x+n)%4==y)
        cout<<"cw";
    else if ((x-n+1000000000)%4==y)
        cout<<"ccw";
    return 0;
}
