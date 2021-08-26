#include <iostream>
#include <string>

using namespace std;
void check(int,int);
int cnt,s;
string str,tmp;

int main()
{
    cin>>str;
    long long unsigned int sum=0;
    s=str.size();
    for(int i=0;i<s;i++)
    {
        sum+=(str[i]-48);
    }
    if(s!=1)
        check(sum,s);
    cout<<cnt;
    return 0;
}
void check(int sum,int s)
{
    int i=0,cnt2=0;
    cnt++;
    while(sum>0)
    {
       tmp[i]=sum%10;
       sum/=10;
       i++;
    }
    for(int j=i-1;j>=0;j--)
    {
        str[i]=tmp[cnt2];
        cnt2++;
    }

    for(int j=0;j<i;j++)
    {
        sum+=(str[j]-48);
    }
    s=i;
    if(i!=1)
        check(sum,s);
    else
    cout<<cnt;
}
