///DARK PROGRAMMER


#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int j=i;
        if(j==1)
            j++;
        ans+=(j-1)*(n-i+1);
    }

    cout<<ans;
    return 0;
}
