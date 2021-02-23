#include <iostream>
#include <set>

using namespace std;

int main()
{
    int q;
    cin >> q;
    set<string> penis;
    while(q-- != 0)
    {
        string word;
        cin >> word;
        penis.insert(word);
    }
    cout << penis.size();
    return 0;
}