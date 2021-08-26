#include <iostream>

using namespace std;

int tabe(int);

int araye[10000];
int tedad ;

int main()
{
    cin>>tedad;
    for (int i=0 ; i<tedad;i++)
    {
        cin>>araye[i];
    }

    for (int i=0 ; i<tedad ; i++)
    {
        if(i!=0)
        {
        if(araye[i]<araye[i-1])
            tabe(i);
        }
    }

    for(int i=0 ; i<tedad ; i++)
        cout << araye[i]<<endl;
    return 0;
}

int tabe(int i)
{
  int x=0 ;
  x=araye[i];
  araye[i]=araye[i-1];
  araye[i-1]=x ;
  if(araye[i-1]<araye[i-2])
    tabe(i-1);
}
