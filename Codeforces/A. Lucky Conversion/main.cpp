#include <iostream>
#include <string>

using namespace std;
int lucky1[100000],lucky2[100000];
int main()
{
    string a,b;
    int n,cnt1=0,cnt2=0,cnt3=0,t=0,ans;
    cin>>a>>b;
    n=a.size();
    for(int i=0;i<n;i++)
    {
        lucky1[i]=a[i]-48;
        lucky2[i]=b[i]-48;
        if(lucky1[i]==4)
            cnt1++;
        if(lucky2[i]==4)
            cnt2++ ;
    }
    for(int i=0;i<n;i++)
      {
          if(lucky1[i]!=lucky2[i])
            cnt3++;
      }
      t=cnt1-cnt2;
      if(t<0)
        t=-t;
      cnt3=cnt3-t;
      ans=(cnt3/2)+t;
      cout<<ans;
      return 0;
}

