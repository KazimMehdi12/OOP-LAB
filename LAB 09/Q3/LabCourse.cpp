#include "LabCourse.h"
#include <iostream>
using namespace std;

LabCourse::LabCourse(string cc, int cr) : Course(cc, cr) {}

double LabCourse::calculateGrade(double marks)
{
    if (marks > 86 && marks <= 100)
    {
        cout << "Grade: A (Lab)" << endl;
    }
    else if (marks > 74 && marks < 86)
    {
        cout << "Grade: B (Lab)" << endl;
    }
    else
    {
        cout << "Grade: C (Lab)" << endl;
    }
    return 0.0;
}

void LabCourse::displayInfo()
{
    cout << "Lab Course: " << courseCode << "\nCredits: " << credits << endl;
}
