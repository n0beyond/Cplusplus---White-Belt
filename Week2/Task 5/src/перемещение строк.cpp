#include <iostream>
#include <vector>
#include <string>

using namespace std;

void MoveStrings (vector<string>& a, vector<string>& b)
{
    for(auto c : a)
    {
        b.push_back(c);
    }
    a.clear();
}

int main() {
    vector<string> source = {"a", "b", "c"};
    vector<string> destination = {"z"};
    MoveStrings(source, destination);
    for(auto c : source)
    {
        cout << c << " ";
    }
    return 0;
}