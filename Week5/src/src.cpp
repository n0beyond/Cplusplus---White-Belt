#include <bits/stdc++.h>

using namespace std;

class Date 
{
public:
    Date(int new_year, int new_month, int new_day)
    {
        year = new_year;
        month = new_month;        
        day = new_day;
    }
    int GetYear() const
    {
        return year;
    }
    int GetMonth() const
    {
        return month;
    }
    int GetDay() const
    {
        return day;
    }
private:
    int year;
    int month;
    int day;
};
ostream& operator<<(ostream& stream, const Date& date)
{
    stream << setfill('0');
    stream << setw(4) << date.GetYear() << '-' << setw(2) << date.GetMonth() << '-' << setw(2) << date.GetDay();
    return stream;
}
bool operator<(const Date& lhs, const Date& rhs)
{
    if(lhs.GetYear() == rhs.GetYear())
    {
        if(lhs.GetMonth() == rhs.GetMonth())
        {
            return(lhs.GetDay() < rhs.GetDay());
        }

        return(lhs.GetMonth() < rhs.GetMonth());
    }
    return(lhs.GetYear() < rhs.GetYear());
} 
bool operator==(const Date& lhs, const Date& rhs)
{
    return (lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth() && lhs.GetDay() == rhs.GetDay());
}
class Database 
{
public:
    void AddEvent(const Date& date, const string& event)
    {
        dbase[date].insert(event);
        /*for(auto& c : dbase[date])
        {
            cout << c << endl;
        }*/
    }
    
    bool DeleteEvent(const Date& date, const string& event)
    {
        return dbase[date].erase(event);
    }
    
    int  DeleteDate(const Date& date)
    {
        int i = dbase[date].size();
        dbase.erase(date);
        return i;
    }
    
    void Find(const Date& date) const
    {
        if(dbase.count(date) == 0)
        {
            return;
        }
        for(const auto& c : dbase.at(date))
        {
           cout << c << endl;
        }
    }
    void Print() const
    {
        for(const auto& c : dbase)
        {
            for(const auto& k : dbase.at(c.first))
            {
                cout << c.first << " " << k << endl;
            }
        }
    }
private:
    map<Date, set<string>> dbase;
};

Date ParseDate(const string& date)
{
    istringstream put(date);
    int year, month, day;
    char def1, def2, a;
    put >> year >> def1 >> month >> def2;
    bool flag = put.peek() == EOF;
    put >> day;
    //cout << year << " " << def1 << " " << month << " " << def2 << " " << day;
    if(def1 != '-' || def2 != '-' || put.peek() != EOF || flag)
    {
        string ss = "Wrong date format: " + date;
        throw invalid_argument(ss);
    }
    if(month <= 0 || month > 12)
    {
        string ss = "Month value is invalid: " + to_string(month);
        throw invalid_argument(ss);
    }
    if(day <= 0 || day > 31)
    {
        string ss = "Day value is invalid: " + to_string(day);
        throw invalid_argument(ss);
    }
    return (Date(year, month, day));
}

int main() 
{
    Database db;
    string command;
    while (getline(cin, command))
    {
        istringstream input(command);
        string huy;
        input >> huy;
        //cout << huy  << endl;
        if(huy == "Add")
        {
        try
        {
            istringstream input(command);
            string command1, date, event;
            input >> command1 >> date >> event;
            Date c = ParseDate(date);
            db.AddEvent(c, event);
        }
        catch (invalid_argument& ex)
        {
            cout << ex.what() << endl;
        }
        }
        else if(huy == "Del")
        {
            try
            {
                istringstream input(command);
                string command1, date, event;
                input >> command1 >> date >> event;
                Date c = ParseDate(date);
                if(event != "")
                {
                    if(db.DeleteEvent(c, event))
                    {
                        cout << "Deleted successfully" << endl;
                    }
                    else
                    {
                        cout << "Event not found" << endl;
                    }
                }
                else
                {
                    cout << "Deleted " << db.DeleteDate(c)
                    << " events" << endl;
                }
            }
            catch (invalid_argument& ex)
            {
                cout << ex.what() << endl;
            }
        }
        else if(huy == "Find")
        {
            try
            {
                istringstream input(command);
                string command1, date, event;
                input >> command1 >> date >> event;
                Date c = ParseDate(date);
                db.Find(c);
            }
            catch (invalid_argument& ex)
            {
                cout << ex.what() << endl;
            }
        }
        else if(huy == "Print")
        {
            db.Print();
        }
        else if (huy != "")
        {
            cout << "Unknown command: " << huy << endl;
        }
    }
    return 0;
}