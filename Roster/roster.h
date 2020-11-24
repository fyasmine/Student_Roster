#ifndef ROSTER_H
#define ROSTER_H
#include <iostream>
#include <string>
#include "student.h"
using namespace std;

const string STUDENT_DATA[] =
{"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Yasmine,F,fyasmine@gmail.com,23,30,30,45,SOFTWARE"};

class Roster {
public:
	Roster();
	void add(string studentID, string firstName, string lastName, string emailAddress, int studentAge,
		int daysInCourse[], Degree degreeType);
	void remove(string studentID);
	void printAll();
	void PrintAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(Degree degreeProgram);
	void divideString(string studentInfo);
	~Roster();
	Student* classRosterArray[5];
	int studentIndex;
	int classRosterSize = 5;
};
#endif