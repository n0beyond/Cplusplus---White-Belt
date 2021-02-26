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

vector<string> PalindromFilter (vector<string> words, int minLength)
{
    vector<string> x;
    for(auto word : words)
    {
        if(IsPalindrom(word) && minLength <= word.size())
        {
            x.push_back(word);
        }
    }
    return x;
}


int main() {
    vector<string> a {"hui", "aaaaaaaaa", "aba", "qqqwqqq", "qqqqqq", "qqqqq"};
    int minLength = 4;
    vector<string> x = PalindromFilter(a, 4);
    for(auto c : x)
    {
        cout << c << ", ";
    }
}