#include <iostream>
#include "student.h"
#include "softwareStudent.h"
using namespace std;

SoftwareStudent::SoftwareStudent() {
	SetSoftwareDegree(Software);
}

void SoftwareStudent::SetSoftwareDegree(Degree software) {
	program = Software;
}

Degree SoftwareStudent::GetDegreeProgram() {
	return program;
}

void SoftwareStudent::print() {
	cout << GetStudentId() << "\t First Name: " << GetFirstName() << "\t Last Name: "
		<< GetLastName() << "\t Age: " << GetStudentAge() << "\t daysInCourse: {"
		<< GetCourseDays()[0] << ", " << GetCourseDays()[1] << ", " << GetCourseDays()[2]
		<< "} \t Degree Program: Software" << endl;
}

SoftwareStudent::~SoftwareStudent() {
	Student::~Student();
}