#include <iostream>
#include <cstring>
#include <string>
#include <unordered_map>
using namespace std;
class student
{
public:
    string firstname;
    string lastname;
    string rollno;
    student(string f, string l, string no)
    {
        firstname = f;
        lastname = l;
        rollno = no;
    }
    bool operator==(const student &s) const
    {
        return rollno == s.rollno ? true : false;
    }
};
class HashFn
{
public:
    size_t operator()(const student &s) const
    {
        return s.firstname.length() + s.lastname.length();
    }
};
int main()
{
    unordered_map<student, int, HashFn> student_map;
    student s1("Prateek", "Narang", "010");
    student s2("Rahul", "Kumar", "023");
    student s3("Prateek", "Gupta", "030");
    student s4("Rahul", "Kumar", "120");
    //add student-marks to hashmap
    student_map[s1] = 100;
    student_map[s2] = 120;
    student_map[s3] = 11;
    student_map[s4] = 45;
    //find marks of s3
    cout << student_map[s3] << endl;
    for (auto s : student_map)
    {
        cout << s.first.firstname << " " << s.first.rollno << " marks=" << s.second << endl;
    }
    return 0;
}