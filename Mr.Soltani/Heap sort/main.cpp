#include <bits/stdc++.h>
#define int long long int
using namespace std;
int minheap[1000000];
int cnt;
int a[100000];
int inf =1e15;
void st(int x)
{
    if(x==1)
        return ;
    if(minheap[x]<minheap[x/2])
        swap(minheap[x],minheap[x/2]);
    st(x/2);
}
void sts(int x)
{
    if(minheap[2*x]<minheap[2*x+1])
    {
        if(minheap[x]>minheap[2*x])
        {
            swap(minheap[x],minheap[2*x]);
            sts(2*x);
        }
    }
    else if(minheap[x]>minheap[2*x+1])
    {
        swap(minheap[x],minheap[2*x+1]);
        sts(2*x+1);
    }

}
void dl()
{
    swap(minheap[1],minheap[cnt]);
    minheap[cnt]=inf;
    sts(1);
}
main()
{
    int n=1000;
    int t[10011];
    for(int i=1;i<=n;i++)
        t[i]=i;
    random_shuffle(&t[0],&t[n+1]);
    for(int i=1;i<=n;i++)
        a[i]=t[i];
    for(int i=1;i<100000;i++)
        minheap[i]=inf;
    minheap[1]=a[1];
    cnt++;
    for(int i=2;i<=n;i++)
    {
        minheap[i]=a[i];
        st(i);
        cnt++;
    }
    for(int i=1;i<=n;i++)
    {
        a[i]=minheap[1];
        dl();
    }
    sort(t+1,t+1001);
    for(int i=1;i<=n;i++)
        if(a[i]!=t[i])
            cout<<"NO";
    cout<<"YES";
    return 0;
}
