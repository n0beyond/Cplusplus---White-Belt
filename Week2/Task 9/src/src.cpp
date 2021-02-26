#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Next(vector<vector<string>>& k, int current_month);

const vector<int> m{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main() {
    int q, day, current_month = 0;
    cin >> q;
    vector<vector<string>> k(31);
    while(q-- != 0)
    {
        string command, thing;
        cin >> command;
        if(command == "ADD")
        {
            cin >> day >> thing;
            k[day - 1].push_back(thing);
        }
        else if(command == "DUMP")
        {
            cin >> day;
            cout << k[day - 1].size() << " ";
            for(auto c : k[day - 1])
            {
                cout << c << " ";
            }
            cout << endl;
        }
        else if(command == "NEXT")
        {
            current_month = (current_month + 1) % 12;
            Next(k, current_month);
        }
    }
    return 0;
}

void Next(vector<vector<string>>& k, int current_month)
{
    for(int i = m[current_month]; i < 31; i++ )
    {
        for(const auto& c : k[i])
        {
            k[m[current_month] - 1].push_back(c);
        }
     k[i].clear();
    }   
}

