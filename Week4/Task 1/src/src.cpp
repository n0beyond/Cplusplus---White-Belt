#include <string>

using namespace std;

struct Specialization
{
    string word;
    explicit Specialization(string new_word)
    {
        word = new_word;
    }
};

struct Course
{
    string word;
    explicit Course(string new_word)
    {
        word = new_word;
    }
};

struct Week
{
    string word;
    explicit Week(string new_word)
    {
        word = new_word;
    }
};

struct LectureTitle 
{
    LectureTitle(Specialization new_s, Course new_c, Week new_w)
    {
        specialization = new_s.word;
        course = new_c.word;
        week = new_w.word;
    }
    string specialization;
    string course;
    string week;
};