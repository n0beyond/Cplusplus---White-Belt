#include <iostream>

using namespace std;


int Factorial(int y)
{
    int x = 1;
    if(y > 1)
    {
        for(int i = 0; i < y; i++)
        {
            x *= (y - i);
        }
    }
    return x;
}


int main() {
    int num;
    cin >> num;
    cout << Factorial(num);
}