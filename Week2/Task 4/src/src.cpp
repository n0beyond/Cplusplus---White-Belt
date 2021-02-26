#include <iostream>

using namespace std;

void UpdateIfGreater(int x, int& y)
{
    if(x > y)
    {
        y = x;
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    UpdateIfGreater(a, b);
    cout << a << b;
    return 0;
}