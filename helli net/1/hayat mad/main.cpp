///Expert




#include <iostream>
#define int long long int
using namespace std;
int a[3][3];
main()
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            cin>>a[i][j];
    cout<<a[0][0]*a[1][1]*a[2][2];
    return 0;
}
