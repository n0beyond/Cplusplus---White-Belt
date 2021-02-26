#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

bool Check(set<string>& m, map<set<string>, int>& mar)
{
    for(auto c : mar)
    {
        if(c.first == m)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int q, bnum = 0;
    cin >> q;
    map<set<string>, int> mar;
    while(q-- != 0)
    {
        set<string> m;
        int k;
        cin >> k;
        for(; k > 0; k--)
        {
            string stop;
            cin >> stop;
            m.insert(stop);
        }
        if(Check(m, mar))
        {
            mar[m] = ++bnum;
            cout << "New bus " << bnum << endl;
        }
        else
        {
            cout << "Already exists for " << mar[m] << endl;
        }
        m.clear();
    }
    return 0;
}