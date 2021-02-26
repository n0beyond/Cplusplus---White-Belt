#include <iostream>
#include <map>
#include <set>

using namespace std;

string Check(map<string, set<string>>& synonyms, string& word1, string& word2)
{
    if(synonyms[word1].count(word2) > 0)
    {
        return "YES";
    }
    return "NO";
}

int main() 
{
    int q;
    cin >> q;
    map<string, set<string>> synonyms;
    while(q-- != 0)
    {
        string command, word1, word2;
        cin >> command;
        if(command == "ADD")
        {
            cin >> word1 >> word2;
            synonyms[word1].insert(word2);
            synonyms[word2].insert(word1);
        }
        else if(command == "COUNT")
        {
            cin >> word1;
            cout << synonyms[word1].size() << endl;
        }
        else if(command == "CHECK")
        {
            cin >> word1 >> word2;
            cout << Check(synonyms, word1, word2) << endl;
        }
    }
    return 0;
}