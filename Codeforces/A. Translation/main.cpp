///DARK PEOGRAMMER


#include <iostream>

using namespace std;

int main()
{
    string ber,bir;
    cin>>ber>>bir;
    int n1=ber.size(),n2=bir.size();
    if(n1!=n2)
    {
        cout<<"NO";
        return 0;
    }
    int j=n1-1;
    for(int i=0;i<n1;i++)
    {
        if(ber[i]!=bir[j])
        {
            cout<<"NO";
            return 0;
        }
        j--;
    }
    cout<<"YES";
    return 0;
}
