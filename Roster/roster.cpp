#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <sstream>
#include "roster.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
using namespace std;

Roster::Roster() {
	studentIndex = 0;
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, 
	int studentAge, int daysInCourse[], Degree degreeType) {
	if (degreeType == Network) {
		classRosterArray[studentIndex] = new NetworkStudent();
	} else if (degreeType == Software) {
		classRosterArray[studentIndex] = new SoftwareStudent();
	} else {
		classRosterArray[studentIndex] = new SecurityStudent();
	}
	classRosterArray[studentIndex]->SetStudentId(studentID);
	classRosterArray[studentIndex]->SetFirstName(firstName);
	classRosterArray[studentIndex]->SetLastName(lastName);
	classRosterArray[studentIndex]->SetEmailAddress(emailAddress);
	classRosterArray[studentIndex]->SetStudentAge(studentAge);
	classRosterArray[studentIndex]->SetCourseDays(daysInCourse);
	++studentIndex;
}

void Roster::remove(string studentID) {
	bool idFound = false;
	for (int i = 0; i < classRosterSize; ++i) {
		if ((classRosterArray[i]) && (classRosterArray[i]->GetStudentId() == studentID) && (classRosterArray[i] != 0)) {
			classRosterArray[i] = 0;
			idFound = true;
			break;
		}
	}
	if (idFound == false) {
		cout << "Student with ID " << studentID << " not found." << endl;
	}
}

void Roster::printAll() {
	for (int i = 0; i < classRosterSize; i++) {
		classRosterArray[i]->print();
	}
}

void Roster::PrintAverageDaysInCourse(string studentID) {
	for (int i = 0; i < classRosterSize; i++) {
		int averageDays = 0;
		if (classRosterArray[i]->GetStudentId() == studentID) {
			int* days = classRosterArray[i]->GetCourseDays();
			for (int j = 0; j < 3; j++) {
				averageDays += days[j];
			}
			cout << studentID << "'s average days in course is " << averageDays / 3 << "." << endl;
		}
	}
}

void Roster::printInvalidEmails() {
	for (int i = 0; i < classRosterSize; i++) {
		bool space = false;
		bool period = false;
		bool atSign = false;
		std::string email = classRosterArray[i]->GetEmailAddress();
		std::size_t found = email.find(" ");
		if (found != std::string::npos) {
			space = true;
		}
		found = email.find(".");
		if (found != std::string::npos) {
			period = true;
		}
		found = email.find("@");
		if (found != std::string::npos) {
			atSign = true;
		}
		if (space || !period || !atSign) {
			cout << email << endl;
		}
	}
}

void Roster::printByDegreeProgram(Degree degreeProgram) {
	for (int i = 0; i < classRosterSize; i++) {
		if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
}

void Roster::divideString(string studentInfo) {
	size_t position = studentInfo.find(",");
	string studentID = studentInfo.substr(0, position);
	size_t position2 = position + 1;
	position = studentInfo.find(",", position2);
	string firstName = studentInfo.substr(position2, position - position2);
	position2 = position + 1;
	position = studentInfo.find(",", position2);
	string lastName = studentInfo.substr(position2, position - position2);
	position2 = position + 1;
	position = studentInfo.find(",", position2);
	string emailAddress = studentInfo.substr(position2, position - position2);
	position2 = position + 1;
	position = studentInfo.find(",", position2);
	string age = studentInfo.substr(position2, position - position2);
	position2 = position + 1;
	position = studentInfo.find(",", position2);
	string courseDaysToComplete1 = studentInfo.substr(position2, position - position2);
	position2 = position + 1;
	position = studentInfo.find(",", position2);
	string courseDaysToComplete2 = studentInfo.substr(position2, position - position2);
	position2 = position + 1;
	position = studentInfo.find(",", position2);
	string courseDaysToComplete3 = studentInfo.substr(position2, position - position2);
	position2 = position + 1;
	position = studentInfo.find(",", position2);
	string programType = studentInfo.substr(position2, position - position2);
	
	Degree degreeType;
	if (programType == "NETWORK") {
		degreeType = Network;
	} else if (programType == "SOFTWARE") {
		degreeType = Software;
	} else {
		degreeType = Security;
	}
	int studentAge = stoi(age);
	int daysInCourse[3] = {stoi(courseDaysToComplete1), stoi(courseDaysToComplete2), stoi(courseDaysToComplete3)};

	add(studentID, firstName, lastName, emailAddress, studentAge, daysInCourse, degreeType);
}

Roster::~Roster() {
	for (int i = 0; i < classRosterSize; i++) {
		classRosterArray[i] = nullptr;
	}
}

int main() {
	cout << "Student Information" << endl <<endl;
	Roster classRoster;
	cout << "All student information:" << endl;
	for (int i = 0; i < 5; i++) {
		string studentInfo = STUDENT_DATA[i];
		classRoster.divideString(studentInfo);
	}
	classRoster.printAll();
	cout << endl << "Invalid emails:" << endl;
	classRoster.printInvalidEmails();
	cout << endl << "Student's average days in course:" << endl;
	for (int i = 0; i < 5; i++) {
		classRoster.PrintAverageDaysInCourse(classRoster.classRosterArray[i]->GetStudentId());
	}
	cout << endl << "All students in software program:" << endl;
	classRoster.printByDegreeProgram(Software);
	cout << endl << "Remove A3:" << endl;
	classRoster.remove("A3");
	classRoster.remove("A3");
}