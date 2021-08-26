#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int cnt=0;
    while(n>0)
    {
        cnt++;
        if(cnt/100>0)
            n-=3;
        else if(cnt/10>0)
            n-=2;
        else
            n-=1;
        //cout<<n<<" "<<cnt<<endl;
    }
    n=-n;
    if(n==0)
        cout<<cnt%10;
    else if(n==1)
    {
        int ans=cnt/10;
        cout<<ans%10;
    }
    else if(n==2&&cnt<100)
    {
        int ans=cnt/10;
        cout<<ans%10;
    }
    else
    {
        int ans=cnt/100;
        cout<<ans%10;
    }
    return 0;
}
