#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    double num;
    ifstream input("input.txt");
    ofstream output("output.txt");
    
    cout << fixed << setprecision(3);

    while (input >> num)
    {
        cout << num << endl;
    }
    return 0;
}