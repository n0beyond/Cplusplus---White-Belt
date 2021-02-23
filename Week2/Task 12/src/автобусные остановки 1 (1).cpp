#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

void NewBus(map<string, vector<string>>& busnstops, vector<string>& buses, map<string, vector<string>>& stops);
void BusesForStop(map<string, vector<string>>& busnstops, vector<string>& buses, map<string, vector<string>>& stops);
void StopsForBus(map<string, vector<string>>& busnstops, const vector<string>& buses, map<string, vector<string>>& stops);

bool operator == (const vector<string>& lhs, const string& rhs);
bool operator == (const string& lhs, const vector<string>& rhs);

int main()
{
    int q;
    cin >> q;
    map<string, vector<string>> busnstops;
    map<string, vector<string>> stops;
    vector<string> buses;
    while(q-- != 0)
    {
        string command;
        cin >> command;
        if(command == "NEW_BUS")
        {
            NewBus(busnstops, buses, stops);
        }
        else if(command == "BUSES_FOR_STOP")
        {
            BusesForStop(busnstops, buses, stops);
        }
        else if(command == "STOPS_FOR_BUS")
        {
            StopsForBus(busnstops, buses, stops);
        }
        else if(command == "ALL_BUSES")
        {
            if(buses.empty())
            {
                cout << "No buses" << endl;
            }
            else
            {
                for(auto k : busnstops)
                    {
                        cout << "Bus " << k.first << ": ";
                        for(auto c : busnstops[k.first])
                        {
                            cout << c << " ";
                        }
                        cout << endl;
                    }
            }
        }
    }
    return 0;
}


void NewBus(map<string, vector<string>>& busnstops, vector<string>& buses, map<string, vector<string>>& stops)
{
    string bus, stop;
    int n;
    cin >> bus >> n;
    buses.push_back(bus);
    while(n-- != 0)
    {
        cin >> stop;
        stops[stop].push_back(bus);
        busnstops[bus].push_back(stop);
    }
}

void BusesForStop(map<string, vector<string>>& busnstops, vector<string>& buses, map<string, vector<string>>& stops)
{
    string stop;
    cin >> stop;
    if(stops[stop].empty())
    {
        cout << "No stop";
        stops.erase(stop);
    }
    else
    {
        for(auto c : buses)
        { 
            for(auto k : busnstops[c])
            {
                if(k == stop)
                {
                    cout << c << " ";
                }
            }
        }
    }
    cout << endl;
}

void StopsForBus(map<string, vector<string>>& busnstops, const vector<string>& buses, map<string, vector<string>>& stops)
{
    string bus;
    cin >> bus;
    if(busnstops[bus].empty())
    {
        cout << "No bus" << endl;
        busnstops.erase(bus);
    }
    else
    {
        for(auto k : busnstops[bus])
            {
                cout << "Stop " << k << ": ";
                vector<string> huy;
                huy.push_back(bus);
                if(stops[k] != huy)
                {
                    for(auto c : stops[k])
                    {
                        if(bus != c)
                        {
                            cout << c << " ";
                        }
                    }
                    cout << endl;
                }
                else
                {
                    cout << "no interchange" << endl;
                }
            }
    }
}
