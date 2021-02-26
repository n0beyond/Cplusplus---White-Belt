#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

class Person
{
public:
    void ChangeFirstName(int year, const string& first_name)
    {
        firstnames[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name)
    {
        lastnames[year] = last_name;
    }
    string GetFullName(int year)
    {
        string fname, lname;
        for (auto elem = firstnames.rbegin(); elem != firstnames.rend(); elem++)
        {
            if (year >= elem->first)
            {
                fname = elem->second;
                break;
            }
        }
        for (auto elem = lastnames.rbegin(); elem != lastnames.rend(); elem++)
        {
            if (year >= elem->first)
            {
                lname = elem->second;
                break;
            }
        }
        if (fname == "" && lname == "")
        {
            return "Incognito";
        }
        else if (fname == "" && lname != "")
        {
            return (lname + " with unknown first name");
        }
        else if (fname != "" && lname == "")
        {
            return (fname + " with unknown last name");
        }
        else
        {
            return (fname + " " + lname);
        }
    }
    string GetFullNameWithHistory(int year)
    {
        string lname, fname, plname, pfname;
        vector<string> fnh;
        vector<string> lnh;
        for (auto elem = firstnames.rbegin(); elem != firstnames.rend(); elem++)
        {
            if (year >= elem->first)
            {
                fnh.push_back(elem->second);
            }
        }
        for (auto elem = lastnames.rbegin(); elem != lastnames.rend(); elem++)
        {
            if (year >= elem->first)
            {
                lnh.push_back(elem->second);
            }
        }
        if(fnh.size() == 0u && lnh.size() == 0u)
        {
            return "Incognito";
        }
        else if (fnh.size() == 0u)
        {
            string result = *lnh.begin();
            string prev = *lnh.begin();
            string appender;
            
            for(size_t i = 1u; i < lnh.size(); i++)
            {
                if(lnh[i] == prev)
                {
                    continue;
                }
                if(!appender.empty())
                {
                    appender += ", ";
                }
                appender += lnh[i];
                prev = lnh[i];
            }
            if(!appender.empty())
            {
                result += " (" + appender + ")";
            }
            return result += " with unknown first name";
        }
        else if (lnh.size() == 0u)
        {
            string result = *fnh.begin();
            string prev = *fnh.begin();
            string appender;
            
            for(size_t i = 1u; i < fnh.size(); i++)
            {
                if(fnh[i] == prev)
                {
                    continue;
                }
                if(!appender.empty())
                {
                    appender += ", ";
                }
                appender += fnh[i];
                prev = fnh[i];
            }
            if(!appender.empty())
            {
                result += " (" + appender + ")";
            }
            return result += " with unknown last name";
        }
        else
        {
            string result = *fnh.begin();
            string prev = *fnh.begin();
            string appender;
            
            for(size_t i = 1u; i < fnh.size(); i++)
            {
                if(fnh[i] == prev)
                {
                    continue;
                }
                if(!appender.empty())
                {
                    appender += ", ";
                }
                appender += fnh[i];
                prev = fnh[i];
            }
            if(!appender.empty())
            {
                result += " (" + appender + ")";
            }
            
            appender.clear();
            
            result += " " + *lnh.begin();
            prev = *lnh.begin();
            
            for(size_t i = 1u; i < lnh.size(); i++)
            {
                if(lnh[i] == prev)
                {
                    continue;
                }
                if(!appender.empty())
                {
                    appender += ", ";
                }
                appender += lnh[i];
                prev = lnh[i];
            }
            if(!appender.empty())
            {
                result += " (" + appender + ")";
            }
            return result;
        }
    }
private:
    map<int, string> firstnames, lastnames;
};