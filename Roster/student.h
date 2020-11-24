#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "degree.h"
using namespace std;

const int COURSE_DAYS_SIZE = 3;

class Student {
public:
	Student();
	void SetStudentId(string inputId);
	void SetFirstName(string inputFirstName);
	void SetLastName(string inputLastName);
	void SetEmailAddress(string inputEmail);
	void SetStudentAge(int inputAge);
	void SetCourseDays(int daysInCourse[]);
	
	string GetStudentId() const;
	string GetFirstName() const;
	string GetLastName() const;
	string GetEmailAddress() const;
	int GetStudentAge() const;
	int* GetCourseDays();

	virtual Degree GetDegreeProgram() = 0;
	virtual void print();
	Degree program;
	~Student();
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int studentAge;
	int daysInCourse[3];
};
#endif
