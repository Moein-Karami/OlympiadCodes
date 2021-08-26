#include <iostream>

using namespace std;
int a1[1000],a2[1000],ans1[1000],ans2[1000];
int main()
{
    int n,ansm=0;
    cin>>n;
    for(int i=1;i<=n ;i++)
    {
        cin>>a1[i]>>a2[i];
        ans1[a1[i]]++;
        ans2[a2[i]]++;
    }
    for(int i=1;i<=100;i++)
    {
        if(ans1[i]&&ans2[i])
            ansm+=ans1[i]*ans2[i];
    }
    cout<<ansm;
    return 0;
}
