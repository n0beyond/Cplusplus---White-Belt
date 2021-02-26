#include <vector>
#include <initializer_list>

using namespace std;

class Incognizable
{
public:
    Incognizable(){}
Incognizable(initializer_list<int> huy1)
{
    for (auto c : huy1)
    {
        huy.push_back(c);
    }
}
private:
    vector<int> huy;
};


int main()
{
    Incognizable a;
    Incognizable b = {};
    Incognizable c = { 0 };
    Incognizable d = { 0, 1 };
    return 0;
}