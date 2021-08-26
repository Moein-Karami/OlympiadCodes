#include <iostream>
#include <vector>
using namespace std;
int f[50][50];
int* q[50][50];
vector <int> b;
int main()
{

    for(int i=0;i<50;i++)
    {
        q[i][0]=f[i];
    }
    for(int i=0;i<50;i++)
    {
        for(int j=1;j<50;j++)
        {
            q[i][j]=q[i][j-1]-1;
        }
    }
    f[0][0]=10;
    cout<<q[0][0];
    return 0;
}
