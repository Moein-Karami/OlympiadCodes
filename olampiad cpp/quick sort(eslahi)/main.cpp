#include <iostream>

using namespace std;

int partition( int A[], int p, int q)
{
	int temp;
	int x = A[p];
	int i = p;
	for (int j = p+1; j <= q; j++)
	{
		if (A[j] <= x)
		{
			i++;
			temp = A[j];
			A[j] = A[i];
			A[i] = temp;
		}
	}
	temp = A[i];
	A[i] = A[p];
	A[p] = temp;
	return i;
}
//

//quick sort
void Quick_sort( int A[], int p,int r)
{
	int q;
	if( p<r)
	{
		q = partition(A,p,r);
		Quick_sort( A, p, q-1);
		Quick_sort( A, q+1, r);
	}
}
//

int main()
{
	//one example
	int i;
	int A[9] = {9,5,7,3,2,1,4,6,0};

	//print array before sort
	for (int i = 0; i < 9; i++)
	{
		cout << A[i]<<" ";
	}
	cout << endl;
	//

	Quick_sort(A,0,8);

	//print array after sort
	for (int i = 0; i < 9; i++)
	{
		cout << A[i]<<" ";
	}
	cout << endl;
	//

	return 0;
}
