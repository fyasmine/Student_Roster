#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H
#include "student.h"
#include "degree.h"
#include <iostream>
using namespace std;

class SoftwareStudent : public Student {
public:
	SoftwareStudent();
	void SetSoftwareDegree(Degree software);
	Degree GetDegreeProgram();
	void print();
	~SoftwareStudent();
};

#endif
