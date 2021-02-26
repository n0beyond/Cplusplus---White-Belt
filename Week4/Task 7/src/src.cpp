#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student
{
    string firstname;
    string lastname;
    int day;
    int month;
    int year;
};

int main() 
{
    int n;
    cin >> n;
    vector<Student> students;
    for(int i = 0; i < n; i++)
    {
        string fname, lname;
        int day, month, year;
        cin >> fname >> lname >> day >> month >> year;
        students.push_back({fname, lname, day, month, year});
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        string command;
        int num;
        cin >> command >> num;
        num--;
        if(command == "name" && num >= 0 && num <= n)
        {
            cout << students[num].firstname << " " << students[num].lastname << endl;
        }
        else if(command == "date" && num >= 0 && num <= n)
        {
            cout << students[num].day << "." << students[num].month << "." << students[num].year << endl;
        }
        else
        {
            cout << "bad request" << endl;
        }
    }
    return 0;
}