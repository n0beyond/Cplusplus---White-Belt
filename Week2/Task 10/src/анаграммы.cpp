#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void BuildCharCounters(const string& word1, const string& word2);

int main() 
{
    int n;
    cin >> n;
    while(n-- != 0)
    {
        string word1, word2;
        cin >> word1 >> word2;
        
        BuildCharCounters(word1, word2);
    }
    return 0;
}

void BuildCharCounters(const string& word1, const string& word2)
{
    map<char, int> huy1;
    map<char, int> huy2;
    for(auto& symbol : word1)
    {
        ++huy1[symbol];
    }
    for(auto& symbol : word2)
    {
        ++huy2[symbol];
    }
    if(huy1 == huy2)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

