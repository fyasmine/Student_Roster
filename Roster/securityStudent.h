#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H
#include "student.h"
#include "degree.h"
#include <iostream>
using namespace std;

class SecurityStudent : public Student {
public:
	SecurityStudent();
	void SetSecurityDegree(Degree security);
	Degree GetDegreeProgram();
	void print();
	~SecurityStudent();
};

#endif
