#include <iostream>

using namespace std;

void tabe(int[],int);

int main()
{
    int n , m , cnt=0 ,cnt1=0;
    cin>>m>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0 ; i<n;i++)
    {
        while(a[i]>=10||a[i]<0)
            a[i]=a[i]/10;
    }

    for (int i=0 ; i<n ; i++)
    {
        if(i!=0)
        {
        if(a[i]<a[i-1])
            tabe(a,i);
        }
    }

    for (int i=0 ; i<n;i++)
    {
        if(a[i]==a[i+1])
        {
            cnt++ ;
        }
        else
        {
            cnt++;
            cnt1+=(cnt/m);
            if(cnt%m!=0)
                cnt1++;
            cnt=1;
        }
    }
    cout<<cnt1+2;
    return 0;
}

void tabe(int a[],int i)
{
  int x=0 ;
  x=a[i];
  a[i]=a[i-1];
  a[i-1]=x ;
  if(a[i-1]<a[i-2])
    tabe(a,i-1);
}
