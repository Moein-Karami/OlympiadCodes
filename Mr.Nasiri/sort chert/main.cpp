///DARK PROGRAMMER


#include <iostream>
#include <algorithm>

using namespace std;
bool soo(const int &a,const int &b)
{
    return a>=b;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n,soo);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
