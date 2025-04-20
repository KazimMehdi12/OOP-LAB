#include "LectureCourse.h"
#include <iostream>
using namespace std;

LectureCourse::LectureCourse(string cc, int cr) : Course(cc, cr) {}

double LectureCourse::calculateGrade(double marks)
{
    if (marks > 86 && marks <= 100)
    {
        cout << "Grade: A (Lecture)" << endl;
    }
    else if (marks > 74 && marks < 86)
    {
        cout << "Grade: B (Lecture)" << endl;
    }
    else
    {
        cout << "Grade: C (Lecture)" << endl;
    }
    return 0.0;
}

void LectureCourse::displayInfo()
{
    cout << "Lecture Course: " << courseCode << "\nCredits: " << credits << endl;
}
