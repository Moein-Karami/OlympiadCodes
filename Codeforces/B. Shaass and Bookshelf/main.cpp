#include <iostream>
#include <algorithm>
using namespace std;
int p[200],p2[200],cnt;
int dp;
pair <int ,int > a[200];
pair <int ,int > a2[200];
pair <int ,int> a3[200];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].second>>a[i].first;
        a3[i].first=a[i].first-a[i].second;
        a3[i].second=i;
    }
    p[-1]=0;
    p2[-1]=0;
    sort(a3,a3+n);


    for(int i=n-1;i>=0;i--)
    {
        a2[cnt].first=a[a3[i].second].first;
        a2[cnt].second=a[a3[i].second].second;
        cnt++;
    }
    for(int i=1;i<n;i++)
    {
        int tmp,tmp2;
        int j=i;
        while((a2[j].first)==(a2[j-1].first-1)&&(a2[j].second )==(a2[j-1].second-1)&&j>=0)
        {

            tmp=a2[j].first;
            tmp2=a2[j].second;
            a2[j].first=a2[j-1].first;
            a2[j].second=a2[j-1].second;
            a2[j-1].first=tmp;
            a2[j-1].second=tmp2;
            j--;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<"<<"<<a2[i].second<<" , "<<a2[i].first<<">>"<<endl;
    }
    for(int i=0;i<n;i++)
    {
        p2[i]=p2[i-1]+a2[i].first;
        p[i]=p[i-1]+a2[i].second;

    }
    cnt=0;
    for(int i=0;i<n;i++)
    {
        if(p[i]>=p2[n-1]-p2[i])
        {
            dp=p[i];
            i=n;
        }

    }
    cout<<dp;
    return 0;
}
