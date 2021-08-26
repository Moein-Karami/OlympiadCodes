///DARK PROGRAMMER


#include <iostream>
#include <algorithm>
#define f first
#define s second
using namespace std;

pair <int,int> a[1000000];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i].f>>a[i].s;
    sort(a,a+n);
    for(int i=n-1;i>0;i--)
    {
        if(a[i].f>a[i-1].f&&a[i].s<a[i-1].s)
        {
            cout<<"Happy Alex";
            return 0;
        }
    }
        cout<<"Poor Alex";
    return 0;
}
