// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string strad, enc;
    char r0, r1;
    int rails;
    cin >> strad >> r0 >> r1 >> enc >> rails;
    vector<string> unores;
    for (int i = 0; i < (int)enc.size(); i++)
    {
        unores.push_back(enc.substr(i, 1));
    }
    vector<int> ct(rails, 0);
    int go = 0;
    int rn = 0;
    for (int i = 0; i < (int)unores.size(); i++)
    {
        ct[rn]++;
        if (go == 0)
        {
            rn++;
        }
        else if (go == 1)
        {
            rn--;
        }
        if (rn == 0)
        {
            go = 0;
        }
        else if (rn == (rails - 1))
        {
            go = 1;
        }
    }
    vector<queue<string>> railord(rails);
    int ctr = 0;
    for (int i = 0; i < (int)ct.size(); i++)
    {
        for (int j = 0; j < ct[i]; j++)
        {
            railord[i].push(unores[ctr]);
            ctr++;
        }
    }
    vector<string> tres;
    go = 0;
    rn = 0;
    for (int i = 0; i < (int)unores.size(); i++)
    {
        tres.push_back(railord[rn].front());
        railord[rn].pop();
        if (go == 0)
        {
            rn++;
        }
        else if (go == 1)
        {
            rn--;
        }
        if (rn == 0)
        {
            go = 0;
        }
        else if (rn == (rails - 1))
        {
            go = 1;
        }
    }
    vector<string> ores;
    int od = 0;
    for (int i = 0; i < tres.size(); i++)
    {
        string inter = tres[i];
        if (tres[i][0] == r0 || tres[i][0] == r1)
        {
            inter.push_back(tres[i + 1][0]);
            i++;
        }
        ores.push_back(inter);
    }
    unordered_map<string, char> mp;
    int ap = 0;
    for (int i = 0; i < 10; i++)
    {
        if (((char)(i + '0')) == r0 || ((char)(i + '0')) == r1)
        {
            continue;
        }
        else
        {
            mp[to_string(i)] = strad[ap];
            ap++;
        }
    }
    for (int i = 8; i < 18; i++)
    {
        string key;
        key.push_back(r0);
        key.push_back((char)(i - 8 + '0'));
        mp[key] = strad[i];
    }
    for (int i = 18; i < 26; i++)
    {
        string key;
        key.push_back(r1);
        key.push_back((char)(i - 18 + '0'));
        mp[key] = strad[i];
    }
    string res;
    for (int i = 0; i < (int)ores.size(); i++)
    {
        res.push_back(mp[ores[i]]);
    }
    cout << res;
}