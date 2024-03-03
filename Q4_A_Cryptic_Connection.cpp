// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string pfkey, vgkey, ctkey, ctxt;
    cin >> pfkey >> vgkey >> ctkey >> ctxt;

    unordered_map<char, int> chfreq;
    set<pair<char, int>> ctset;
    vector<pair<char, int>> octkey;
    for (int i = 0; i < (int)ctkey.size(); i++)
    {
        octkey.push_back(make_pair(ctkey[i], chfreq[ctkey[i]]));
        ctset.insert(make_pair(ctkey[i], chfreq[ctkey[i]]));
        chfreq[ctkey[i]]++;
    }

    int ct = 0;
    int sz = ctxt.size() / ctkey.size();
    map<pair<char, int>, string> tokstr;
    for (auto it : ctset)
    {
        tokstr[it] = ctxt.substr(ct * sz, sz);
        ct++;
    }

    vector<string> ctmat;
    for (auto it : octkey)
    {
        ctmat.push_back(tokstr[it]);
    }
    string octf;
    int flg = 0;
    for (int i = 0; i < sz; i++)
    {
        for (int j = 0; j < ctkey.size(); j++)
        {
            if (ctmat[j][i] == 'X')
            {
                flg = 1;
                break;
            }
            octf.push_back(ctmat[j][i]);
        }
        if (flg)
        {
            break;
        }
    }

    string evgkey;
    for (int i = 0; i < (int)octf.size(); i++)
    {
        evgkey.push_back(vgkey[i % vgkey.size()]);
    }
    string ovgf;
    for (int i = 0; i < (int)octf.size(); i++)
    {
        ovgf.push_back((char)((octf[i] - evgkey[i] + 26) % 26 + 'A'));
    }
    // cout<<ovgf;
    unordered_set<char> pfit;
    vector<string> pfmat(5);
    unordered_map<char, pair<int, int>> fmp;
    int c = 0;
    for (int i = 0; i < (int)(pfkey.size()); i++)
    {
        if (pfit.find(pfkey[i]) == pfit.end())
        {
            pfmat[c / 5].push_back(pfkey[i]);
            fmp[pfkey[i]] = make_pair(pfmat[c / 5].size() - 1, c / 5);
            c++;
            pfit.insert(pfkey[i]);
        }
    }
    for (int i = 0; i < 26; i++)
    {
        char here = (char)('A' + i);
        if (here == 'J')
        {
            continue;
        }
        if (pfit.find(here) == pfit.end())
        {
            pfmat[c / 5].push_back(here);
            fmp[here] = make_pair(pfmat[c / 5].size() - 1, c / 5);
            c++;
            pfit.insert(here);
        }
    }
    string oplf, res;
    int siz = ovgf.size() / 2;
    for (int i = 0; i < siz; i++)
    {
        string tmp = ovgf.substr(2 * i, 2);
        if (fmp[tmp[0]].first == fmp[tmp[1]].first)
        {
            oplf.push_back(pfmat[(fmp[tmp[0]].second + 4) % 5][fmp[tmp[0]].first]);
            oplf.push_back(pfmat[(fmp[tmp[1]].second + 4) % 5][fmp[tmp[1]].first]);
        }
        else if (fmp[tmp[0]].second == fmp[tmp[1]].second)
        {
            oplf.push_back(pfmat[fmp[tmp[0]].second][(fmp[tmp[0]].first + 4) % 5]);
            oplf.push_back(pfmat[fmp[tmp[1]].second][(fmp[tmp[1]].first + 4) % 5]);
        }
        else
        {
            oplf.push_back(pfmat[fmp[tmp[0]].second][fmp[tmp[1]].first]);
            oplf.push_back(pfmat[fmp[tmp[1]].second][fmp[tmp[0]].first]);
        }
    }
    cout << oplf;
}