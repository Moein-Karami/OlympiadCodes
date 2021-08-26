#include <iostream>

using namespace std;
int a[31];
int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    char c;
    for(int i=1;i<=n;i++)
    {
        cin>>c;
        a[c-'a']++;
    }
    for(int i=0;i<30;i++)
    {
        if(a[i]>m)
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}
