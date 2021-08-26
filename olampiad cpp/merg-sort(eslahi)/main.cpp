#include <iostream>

using namespace std;

void merg_sort(int,int);
void merg(int,int);

int a[1000];
int temp[10000];

int main()
{
    int n;
    cin >> n ;
    for(int i=0;i<n;i++)
        cin>>a[i];
    merg_sort( 0 , n);
    for(int i=0 ; i<n ; i++)
        cout << a[i]<<"  ";
    return 0;
}

void merg_sort(int l , int r)
    {
        if(r>=l)
        {
            int mid ;
            mid=(l+r)/2;
            merg_sort( l , mid);
            merg_sort( mid+1 , r);
            merg( l , r);
        }
    }

void merg(int l  , int r)
{
    int temp=0;
  if (a[l]>a[r])
  {
    temp=a[r];
    a[r]=a[l];
    a[l]=temp;
  }

}
