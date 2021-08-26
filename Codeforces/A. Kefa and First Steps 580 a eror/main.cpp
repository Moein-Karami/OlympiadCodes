#include <iostream>

using namespace std;
int day[1000000];
int main()
{
    long long int n;
    cin>>n;
    long long int cnt=0,max=0;
    for(long long int i=0;i<n;i++)
        cin>>day[i];
    for(long long int i=1;i<n;i++)
    {

        if(day[i]>=day[i-1])
        {
            cnt++;
        }
        else
        {
            cnt++;
            if(cnt>max)
                max=cnt;
            cnt=0;
        }
        if(i==n-1)
        {
            cnt++;
            if(cnt>max)
                max=cnt;
            cnt=0;
        }
    }
    cout<<max;
    return 0;
}
