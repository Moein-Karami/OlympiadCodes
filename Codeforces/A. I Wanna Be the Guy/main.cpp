#include <iostream>

using namespace std;
bool b[10000];
int a[100000];
int a1[100000];
int main()
{int n;cin>>n;int m;cin>>m;for(int i=1;i<=m;i++){cin>>a[i];b[a[i]]=1;}int f;cin>>f;for(int i=1;i<=f;i++){cin>>a1[i];b[a1[i]]=1;}bool b1=1;for(int i=1;i<=n;i++){if(!b[i])b1=0;}if(b1)cout<<"I become the guy.";else cout<<"Oh, my keyboard!";return 0;}
