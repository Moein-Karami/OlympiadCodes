///Chefer


#include <bits/stdc++.h>

using namespace std;

main()
{
    int n;
    cin>>n;
    string s;
    int t;
    stack <int> st;
    cin>>s;
    cin>>t;
    st.push(t);
    for(int i=1;i<2*n;i++)
    {
        cin>>s>>t;
        if(s[0]=='i')
        {
            cout<<st.top()<<" "<<t<<endl;
            st.push(t);
        }
        else
            st.pop();
    }
    return 0;
}
