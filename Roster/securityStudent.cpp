#include <iostream>
#include "student.h"
#include "securityStudent.h"
using namespace std;

SecurityStudent::SecurityStudent() {
	SetSecurityDegree(Security);
}

void SecurityStudent::SetSecurityDegree(Degree security) {
	program = security;
}

Degree SecurityStudent::GetDegreeProgram() {
	return program;
}

void SecurityStudent::print() {
	cout << GetStudentId() << "\t First Name: " << GetFirstName() << "\t Last Name: "
		<< GetLastName() << "\t Age: " << GetStudentAge() << "\t daysInCourse: {"
		<< GetCourseDays()[0] << ", " << GetCourseDays()[1] << ", " << GetCourseDays()[2]
		<< "} \t Degree Program: Security" << endl;
}

SecurityStudent::~SecurityStudent() {
	Student::~Student();
}