///DARK PROGRAMMER


#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a,a+n);
    int l=-1,r=-1;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=b[i])
        {
            l=i;
            i=n;
            break;
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]!=b[i])
        {
            r=i;
            i=-1;
            break;
        }
    }
    if(l==-1)
    {
        cout<<"yes"<<endl;
        cout<<1<< " "<<1;
        return 0;
    }
    int t=l,t1=r;
    while(r>l)
    {
        swap(b[l],b[r]);
        r--;
        l++;
    }
    //for(int i=0;i<n;i++)
    //{
      //  cout<<b[i]<<" ";
    //}
    for(int i=0;i<n;i++)
    {
        if(a[i]!=b[i])
        {
            cout<<"no";
            return 0;
        }
    }
    cout<<"yes"<<endl;
    cout<<t+1<<" "<<t1+1;
    return 0;
}
