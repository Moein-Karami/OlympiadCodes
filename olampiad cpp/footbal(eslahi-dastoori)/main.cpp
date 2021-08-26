#include <iostream>
#include <vector>

using namespace std;

pair<int,int> footbal[10000];

int main()
{
    int n , x , y , q=0 , j;
    cin >> n;
    for ( int i=0 ; i<n ; i++)
    {
        cin>>y ;
        footbal[i].second=y ;
        cin>> x ;
        footbal[i].first = x;
    }
    sort(footbal[0],footbal[n]);

    for (int i=0 ; i<n ; i++)
    {
        y=footbal[i].first;
        j=i+1;
        while(y>footbal[j].second)
        {
            j++;
            i++;
        }
        q++;
    }
    cout<<q;
    return 0;
}
