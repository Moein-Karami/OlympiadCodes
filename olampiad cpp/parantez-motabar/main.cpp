#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    stack <char> pa ;
    string mo;
    bool valid = true;

    cin >>mo;
    int s=mo.size();

    for(int i=0 ; i<s ; i++)
    {
        if(mo[i]==')')
        {
            if(pa.empty())
               valid = false;
            else
                pa.pop();
        }

        else pa.push('(');
    }

    if(valid && pa.empty())
        cout << "Valid" << endl;

    else
        cout << "Invalid" << endl;

    return 0;
}
