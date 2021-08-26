#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double n,sum=0;
    cin>>n;
    int s=n;
    double a[s];
    for(int i=0;i<s;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    cout<<setprecision(12);
    cout<<std::fixed;
    cout<<sum/n;

    return 0;
}
