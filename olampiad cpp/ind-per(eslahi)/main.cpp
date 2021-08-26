#include <iostream>

using namespace std;
void c(int);

int mabna[1000000];
int per[1000000];

int main()
{
    int n,x,ind , temp,temp2;
    cin >>n;
    temp=n;
    temp2=temp;
    int fact[n+1];
    fact[1]=1;
    cin>>ind;
    ind--;
    for (int i=2 ; i<=n ; i++)
    {
      fact[i]=i*fact[i-1];
    }
    for(int i=0;i<n;i++)
    {
        mabna[i]= i;
    }

    for (int i=0;i<temp2;i++)
    {
        x=ind/(fact[n]/n);
        per[i]=x;
        c(i);
        ind=ind-(x*(fact[n]/n));
        n=n-1;
    }
    for(int i=0;i<temp;i++)
        cout<<per[i];
    return 0;
}

void c(int j)
{
    for (int i=0;i<=per[j];i++)
    {
        if(mabna[i]==-1)
            per[j]++;
    }
    mabna[per[j]]=-1;
}
