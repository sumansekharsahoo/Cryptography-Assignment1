// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string kword, polystr, txt;
    cin >> kword >> polystr >> txt;
    string c0 = "CRYPTO";
    string c1 = "GRAPHY";
    unordered_map<char, string> mp;
    for (int i = 0; i < 36; i++)
    {
        mp[polystr[i]].push_back(c0[i / 6]);
        mp[polystr[i]].push_back(c1[i % 6]);
    }
    string rim;
    for (int i = 0; i < (int)txt.size(); i++)
    {
        rim += mp[txt[i]];
    }
    int ksz = kword.size();
    int rsz = rim.size();
    if (rsz % ksz)
    {
        int ext = ((rsz / ksz) + 1) * ksz - rsz;
        for (int i = 0; i < ext; i++)
        {
            rim.push_back('X');
        }
    }
    rsz = rim.size();
    map<string, string> fmp;
    for (int i = 0; i < rsz; i++)
    {
        string key;
        key.push_back(kword[i % ksz]);
        key.push_back((char)(i % ksz + '0'));
        fmp[key].push_back(rim[i]);
    }
    string res;
    for (auto it : fmp)
    {
        res += it.second;
    }
    cout << res;
}