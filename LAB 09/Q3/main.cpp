#include "LectureCourse.h"
#include "LabCourse.h"

int main() {
    Course* course1 = new LectureCourse("CS101", 3);
    Course* course2 = new LabCourse("CS101L", 1);

    course1->displayInfo();
    course1->calculateGrade(92);
    course2->displayInfo();
    course2->calculateGrade(78);

    delete course1;
    delete course2;

    return 0;
}
