#include <iostream>
#include <vector>

using namespace std;

vector<int> Reversed(const vector<int>& v)
{
    vector<int> x;
    for(int i = v.size() - 1, f = 0; f < v.size(); f++, i--)
    {
         x.push_back(v[i]);
    }
    return x;
}

int main() {
    vector<int> numbers = {1, 5, 3, 4, 2};
    Reversed(numbers);
    return 0;
}