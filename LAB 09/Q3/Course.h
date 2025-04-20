#pragma once
#include <iostream>
using namespace std;

class Course
{
protected:
   string courseCode;
   int credits;

public:
   Course(string code, int cr) : courseCode(code), credits(cr) {}

   virtual double calculateGrade(double marks) = 0;
   virtual void displayInfo() = 0;
   virtual ~Course() {}
};
