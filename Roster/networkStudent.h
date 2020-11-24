#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H
#include "student.h"
#include "degree.h"
#include <iostream>
using namespace std;

class NetworkStudent : public Student {
public:
	NetworkStudent();
	void SetNetworkDegree(Degree network);
	Degree GetDegreeProgram();
	void print();
	~NetworkStudent();
};

#endif
