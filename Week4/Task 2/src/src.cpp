#include <vector>
#include <algorithm>

using namespace std;

class Funpart
{
    public:
    Funpart(char new_operation, double new_value)
    {
       value = new_value;
       operation = new_operation;
    }
    double Apply(double source_value) const
    {

        if(operation == '+')
        {
            source_value += value;
        }
        else
        {
            source_value -= value;
        }
    return source_value;
    }
    void Invert()
    {
        if(operation == '+')
        {
            operation = '-';
        }
        else
        {
            operation = '+';
        }
    }
    private:
    char operation;
    double value;
};

class Function
{
  public:
  void AddPart(char operation, double value)
  {
      funelems.push_back({operation, value});
  }
  double Apply(double value) const
  {
      for (const auto& e : funelems)
      {
          value = e.Apply(value);
      }
      return value;
  }
  void Invert()
  {
    for(auto& e : funelems)
    {
       e.Invert();
    }
    reverse(begin(funelems), end(funelems));
  }
  private:
  vector<Funpart> funelems;
};