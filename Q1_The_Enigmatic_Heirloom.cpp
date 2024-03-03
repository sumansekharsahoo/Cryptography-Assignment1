// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    char sc0, sc1;
    cin >> sc0 >> sc1;
    string inp;
    cin >> inp;
    string res;
    int sz = inp.size() / 5;
    for (int i = 0; i < sz; i++)
    {
        string imd;
        for (int j = i * 5; j < (i * 5 + 5); j++)
        {
            imd.push_back(inp[j]);
        }
        for (int j = 0; j < 5; j++)
        {
            imd[j] = (char)(imd[j] - sc0 + '0');
            if (imd[j] != '0')
            {
                imd[j] = '1';
            }
        }
        res.push_back((char)('A' + stoi(imd, nullptr, 2)));
    }
    cout << res;
}