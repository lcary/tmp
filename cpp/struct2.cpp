#include <iostream>
#include <string>

using namespace std;

// Using hierarchical structures

struct Date
{
    int day;
    int month;
    int year;
};

struct Professor
{
    string name;
    string department;
    Date startDate;
    bool tenured;
};

struct Class
{
    string name;
    int credits;
    Professor prof;
};

void fillClassInfo(Class& aClass);

void printClassInfo(Class aClass);

int main() {

    Class myClass;

    fillClassInfo(myClass);
    printClassInfo(myClass);

    return 0;
}

void fillClassInfo(Class& aClass)
{
    Date date = {21, 11, 2003};

    Professor prof;
    prof.name = "Phil Collins";
    prof.department = "Computer Science";
    prof.startDate = date;
    prof.tenured = true;

    aClass = {"CS101", 3, prof};
}

void printClassInfo(Class aClass)
{
    cout << aClass.prof.name << " is teaching " << aClass.name << " this year.\n";
    cout << "He started teaching here back in " << aClass.prof.startDate.year << ".\n";
}
