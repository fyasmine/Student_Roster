#include <iostream>
#include "student.h"
#include "networkStudent.h"
using namespace std;

NetworkStudent::NetworkStudent() {
	SetNetworkDegree(Network);
}


void NetworkStudent::SetNetworkDegree(Degree network) {
	program = network;
}

Degree NetworkStudent::GetDegreeProgram() {
	return program;
}

void NetworkStudent::print() {
	cout << GetStudentId() << "\t First Name: " << GetFirstName() << "\t Last Name: "
		<< GetLastName() << "\t Age: " << GetStudentAge() << "\t daysInCourse: {"
		<< GetCourseDays()[0] << ", " << GetCourseDays()[1] << ", " << GetCourseDays()[2]
		<< "} \t Degree Program: Network" << endl;
}

NetworkStudent::~NetworkStudent() {
	Student::~Student();
}