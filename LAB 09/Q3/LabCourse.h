#pragma once
#include "Course.h"

class LabCourse : public Course {
public:
    LabCourse(string cc, int cr);

    double calculateGrade(double marks);
    void displayInfo();
    
};
