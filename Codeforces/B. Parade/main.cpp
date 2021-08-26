#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int l[n];
    int r[n];
    int sl=0,sr=0;
    for(int i=0;i<n;i++)
    {
        cin>>l[i]>>r[i];
        sl+=l[i];
        sr+=r[i];
    }
    int tmpr=sr,tmpl=sl,a=fabs(sr-sl),p=0;
    for(int i=0;i<n;i++)
    {
        tmpr=tmpr-r[i]+l[i];
        tmpl=tmpl-l[i]+r[i];
        if(fabs(tmpr-tmpl)>a)
        {
            a=fabs(tmpr-tmpl);
            p=i+1;
        }
        tmpr=sr;
        tmpl=sl;
    }
    cout<<p;
    return 0;
}
