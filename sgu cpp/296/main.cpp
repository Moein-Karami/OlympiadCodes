#include <iostream>

using namespace std;

void merge_sort(int[],int,int);
void merg(int[],int,int,int);

int a[1000+1];
int temp[1000+1];

int main()
{
    unsigned int n, cnt=0,cnt1=0 ;
    long unsigned m , tmp;
    cin>>m>>n;
    int b[n];
    tmp=m;
    while(tmp!=0)
    {
        temp[cnt]=tmp%10;
        tmp=tmp/10;
        cnt++;
    }

    if(cnt==n)
    {
        cout<<0;
        return 0 ;
    }

    for (int i=cnt-1;i>=0;i--)
    {
        a[cnt1]=temp[i];
        cnt1++;
    }
    cnt1=0;

    merge_sort(temp,0,cnt-1);

    for(int i=0 ; i<n ; i++)
        b[i]=temp[i];



    for(int i=0 ; i<cnt;i++)
    {
        if(cnt1!=n)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i]==b[j])
                {
                    a[i]=-1;
                    b[j]=-2;
                }
            }
        }

        if(a[i]!=-1)
            cout<<a[i];
        else
            cnt1++;
    }

    return 0;
}
void merge_sort(int arr[], int low, int high)
{
    if(low >= high)
    return;
    int mid = (low + high) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merg(arr, low, mid, high);
}
void merg(int arr[], int low, int mid, int high)
{
 	  int i, j, k, t;
 	  j = low;
 	  for(i = mid + 1 ; i <= high ; i++){
	    while(arr[j] <= arr[i] && j < i)
	      j++;
 	    if(j == i)
 	      break;
 	    t = arr[i];
 	    for(k = i ; k > j ; k --)
	      arr[k] = arr[k - 1];
 	    arr[j] = t;
 	  }
 	}
