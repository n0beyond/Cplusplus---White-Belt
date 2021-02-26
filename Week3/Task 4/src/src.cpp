#include <iostream>
#include <map>
#include <set>

using namespace std;

class Person
{
public:
    void ChangeFirstName(int year, const string& first_name)
    {
        year_names[year]["firstname"] = (first_name);
        years.insert(year);
    }
    void ChangeLastName(int year, const string& last_name)
    {
        years.insert(year);
        year_names[year]["lastname"] = (last_name);
    }
    string GetFullName(int year)
    {
        years.insert(year);
        string fname, lname;
        for (auto& c : years)
        {
            if (c <= year)
            {
                if (year_names[c]["firstname"] != "")
                {
                    fname = year_names[c]["firstname"];
                }
                if (year_names[c]["lastname"] != "")
                {
                    lname = year_names[c]["lastname"];
                }
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
private:
    map<int, map<string, string>> year_names;
    set<int> years;
};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}