///Chefer


#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x,y;
    cin>>x>>y;
    int r;
    cin>>r;
    int dx,dy;
    cin>>dx>>dy;
    if(dx>=x&&dx<=x+r&&dy<=y&&dy>=y-r)
        cout<<"Mahdi";
    else
        cout<<"Parsa";
    return 0;
}
