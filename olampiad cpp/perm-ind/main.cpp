#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
const int N = 1000 + 10;
int n, a[N], b[N];
ull ind = 1, fact[N];

int find(int x)
{
    int c = 0;

    for(int i = 0 ; i < n ; i++)
    {
        if(b[i] == x)
        {
            b[i] = -1;
            return c;
        }

        else if(b[i] != -1)
            c++;
    }
}

inline void factorial()
{
    fact[1] = 1;

    for(int i = 2 ; i < n ; i++)
       fact[i] = fact[i-1] * i;
}

inline void perIndex()
{
    int p = n - 1;

    for(int i = 0 ; i < n - 1 ; i++)
        ind += fact[p--] * find(a[i]);
}

int main()
{
    cin >> n;

    factorial();

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = i;
    }

    perIndex();

    cout << ind << endl;
    return 0;
}
