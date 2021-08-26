#include <iostream>

using namespace std;
void check(int a[])
{
    cout<<a[0]<<endl;
    a[0]=5;
}
int main()
{
    int a[1000];
    check(a);
    cout<<a[0];
    return 0;
}
