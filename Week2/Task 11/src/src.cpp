#include <iostream>
#include <map>
#include <string>

using namespace std;

void ChangeCapital(map <string, string>& directory);
void Rename(map <string, string>& directory);
void About(map <string, string>& directory);

int main ()
{
  int q;
  cin >> q;
  map < string, string > directory;
  while (q-- != 0)
    {
      string command;
      cin >> command;
          if (command == "CHANGE_CAPITAL")
    	  {
                ChangeCapital(directory);
    	  }
    	  else if(command == "RENAME")
    	  {
    	      Rename(directory);
    	  }
    	  else if(command == "ABOUT")
    	  {
    	      About(directory);
    	  }
    	  else if(command == "DUMP")
    	  {
    	      if(directory.empty())
    	      {
    	          cout << "There are no countries in the world" << endl;
    	      }
    	      else
    	      {
    	          for(auto c : directory)
    	          {
    	              cout << c.first << "/" << c.second << " ";
    	          }
    	          cout << endl;
    	      }
    	  }
    }
    return 0;
}

void ChangeCapital(map <string, string>& directory)
{
    int i = 0;
    string country, new_capital;
    cin >> country >> new_capital;
        for(auto c : directory)
        {
            if(c.first == country)
            {
                i++;
            }
        }
    if(i)
    {
        if(directory[country] == new_capital)
        {
            cout << "Country " << country << " hasn't changed its capital" << endl;
        }
        else
        {
            cout << "Country " << country << "  has changed its capital from " << directory[country] << " to ";
            directory[country] = new_capital;
            cout << directory[country] << endl;
        }
    }
    else
    {
        cout << "Introduce new country " << country << " with capital " << new_capital << endl;
        directory[country] = new_capital;
    }
}

void Rename(map <string, string>& directory)
{
    int i = 0;
    string old_country_name, new_country_name;
    cin >> old_country_name >> new_country_name;
    for(auto c : directory)
    {
        if(c.first == old_country_name && old_country_name != new_country_name && directory[new_country_name].empty())
            {
                i++;
            }
    }
    if(i)
    {
        directory[new_country_name] = directory[old_country_name];
        directory.erase(old_country_name);
        cout << "Country " << old_country_name << " with capital " << directory[new_country_name] << " has been renamed to " << new_country_name << endl;
    }
    else
    {
        cout << "Incorrect rename, skip" << endl;
    }
}

void About(map <string, string>& directory)
{
    string country;
    cin >> country;
    if(directory[country].empty())
    {
        cout << "Country " << country << " doesn't exist " << endl;
        directory.erase(country);
    }
    else
    {
        cout << "Country " << country << " has capital " << directory[country] << endl;
    }
}
