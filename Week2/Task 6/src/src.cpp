#include <iostream>
#include <vector>

using namespace std;

void Reverse (vector<int>& v)
{
    vector<int> x = v;
    for(int i = v.size() - 1, f = 0; f < v.size(); f++, i--)
    {
        v[f] = x[i];
    }
}

int main() {
    vector<int> numbers = {1, 5, 3, 4, 2};
    Reverse(numbers);
    for(auto c : numbers)
    {
        cout << c << " ";
    }
    return 0;
}