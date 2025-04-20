#pragma once
#include "Course.h"

class LectureCourse : public Course {
public:
    LectureCourse(string cc, int cr);
    
    double calculateGrade(double marks);
    void displayInfo();
};
