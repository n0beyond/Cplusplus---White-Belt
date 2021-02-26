#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

std::string to_lower(const std::string& st);

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::string> vec;
    
    while (n-- != 0)
    {
        std::string tmp;
        std::cin >> tmp;
        vec.push_back(tmp);
    }
    
    std::sort(vec.begin(), vec.end(), [](const std::string& lhs, const std::string& rhs) {
        
        return to_lower(lhs) < to_lower(rhs);
    });
    
    for (const std::string& one : vec) {
        std::cout << one << " ";
    }
}

std::string to_lower(const std::string& st) 
{
    std::string result;
    
    for (char c : st) {
        int tmp = static_cast<int>(c);
        if (c < 91 && c > 64) {
            c += 32;
        }
        result.push_back(static_cast<char>(c));
    }
    return result;
}