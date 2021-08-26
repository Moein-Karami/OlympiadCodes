///Chefer


#include <bits/stdc++.h>

using namespace std;

int main()
{
    int r,c;
    cin>>r>>c;
    if(c<11)
        cout<<"Right "<<10-r+1<<" "<<c;
    else
        cout<<"Left "<<10-r+1<<" "<<20-c+1;

    return 0;
}
