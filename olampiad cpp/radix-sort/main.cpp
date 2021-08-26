#include <iostream>

using namespace std;

int arr[10000] ,temp[10000] ,temp2[10000],cnt[10000] , cou[10000];

int main()
{
    int n , max=0 , max2=0 , cn=0 ;
    cin>>n;
    for (int i=0 ; i<n ; i++)
    {
        cin>>arr[i];
        temp[i]=arr[i];
        temp2[i]=arr[i];
        if(arr[i]>max2)
            max2=arr[i];
    }
    while(max2!=0)
    {
        max2=max2/10;
        cn++;
    }

    for (int j=1;j<=cn;j++)
    {
        for (int i=0 ; i<n ; i++)
        {
            cnt[temp2[i]%10]++;
            if(temp2[i]%10>max)
                max=temp2[i]%10;
        }

        for(int i=1;i<=max;i++)
        {
                cnt[i]+=cnt[i-1];
        }

        for(int i=n-1 ; i>=0;i--)
        {
            cnt[temp2[i]]--;
            cou[cnt[temp2[i]]]=temp[i];
        }
        for(int i=0 ; i<n;i++)
        {
            temp2[i]=temp2[i]/10;
        }
        for ( int i=0 ; i<=max ; i++)
            cnt[i]=0;
            max=0;

    }
    for(int i=0; i<n;i++)
        cout<<cou[i]<<endl;
    return 0;
}
