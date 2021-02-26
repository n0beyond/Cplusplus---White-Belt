#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    double num;
    int a, b;
    ifstream input("input.txt");
    input >> a >> b;
    cout << fixed << setprecision(0);
    for (int z = 0; z < a; z++)
    {
        int x = 0;
        for (; x < b; x++)
        {
            input >> num;
            if (x != b - 1)
            {
                cout << setw(10) << num << " ";
                input.ignore(1);
            }
            else
            {
                cout << setw(10) << num;
            }
        }
        if (z != a - 1)
        {
            cout << endl;
        }
    }
    return 0;
}
