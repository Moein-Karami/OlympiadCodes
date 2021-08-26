#include <iostream>

using namespace std;
int  one[10000];
int two[10000];
int three[10000];
int a[10000];
int main()
{
    int n;
    cin>>n;
    int cnt1=0,cnt2=0,cnt3=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1)
        {
            cnt1++;
            one[cnt1]=i;
        }
        if(a[i]==2)
        {
            cnt2++;
            two[cnt2]=i;
        }
        if(a[i]==3)
        {
            cnt3++;
            three[cnt3]=i;
        }
    }
    int mini=1e9;
    mini=min(cnt1,cnt2);
    mini=min(mini,cnt3);
    cout<<mini<<endl;
    for(int i=1;i<=mini;i++)
    {
        cout<<one[i]<<" "<<two[i]<<" "<<three[i]<<endl;
    }
    return 0;
}
