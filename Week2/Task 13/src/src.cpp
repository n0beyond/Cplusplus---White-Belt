#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool Check(vector<string> m, map<vector<string>, int> mar)
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
    map<vector<string>, int> mar;
    while(q-- != 0)
    {
        vector<string> m;
        int k;
        cin >> k;
        for(; k > 0; k--)
        {
            string stop;
            cin >> stop;
            m.push_back(stop);
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
}