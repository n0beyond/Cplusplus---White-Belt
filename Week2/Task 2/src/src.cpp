#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsPalindrom(string word)
{
    for (int i = 0, j = word.size() - 1; i < word.size(); i++, j--)
    {
        if  (word[i] != word[j])
        {
            return false;
        }
    }
    return true;
}


int main() {
    string a;
    cin >> a;
    cout << IsPalindrom(a);
}