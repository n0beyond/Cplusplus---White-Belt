#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int abs(int x);
int main()
{
    int q;
    cin >> q;
    vector<int> nums;
    for(; q > 0; q--)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end(), [](int x, int y) { return abs(x) < abs(y); });
    for(int i : nums)
    {
        cout << i << " ";
    }
}

int abs(int x)
{
    if(x < 0)
    {
        return -x;
    }
    return x;
}