#include <iostream>
#include "student.h"
#include "roster.h"

using namespace std;

Student::Student() {
	studentID = " ";
	firstName = " ";
	lastName = " ";
	emailAddress = " ";
	studentAge = 0;
	daysInCourse[3] = 0;
	program = Software;
}

void Student::SetStudentId(string inputId) {
	studentID = inputId;
}

void Student::SetFirstName(string inputFirstName) {
	firstName = inputFirstName;
}

void Student::SetLastName(string inputLastName) {
	lastName = inputLastName;
}

void Student::SetEmailAddress(string inputEmail) {
	emailAddress = inputEmail;
}

void Student::SetStudentAge(int inputAge) {
	studentAge = inputAge;
}

void Student::SetCourseDays(int courseDays[]) {
	daysInCourse[0] = courseDays[0];
	daysInCourse[1] = courseDays[1];
	daysInCourse[2] = courseDays[2];
}

string Student::GetStudentId() const {
	return studentID;
}

string Student::GetFirstName() const {
	return firstName;
}

string Student::GetLastName() const {
	return lastName;
}

string Student::GetEmailAddress() const {
	return emailAddress;
}

int Student::GetStudentAge() const {
	return studentAge;
}

int* Student::GetCourseDays() {
	return daysInCourse;
}

void Student::print() {
}

Student::~Student() {
}
