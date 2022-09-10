#include <iostream>

using namespace std;

#include "roster.h"

void Roster::parse(string row) {
	size_t rhs = row.find(",");
	string studentID = row.substr(0, rhs);

	size_t lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string firstName = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string lastName = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string emailAddress = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int age = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int daysInCourse1 = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int daysInCourse2 = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int daysInCourse3 = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string strDegreeProgram = row.substr(lhs, rhs - lhs);

	DegreeProgram degreeProgram;

	if (strDegreeProgram == "SECURITY") {
		degreeProgram = SECURITY;
	}
	else if (strDegreeProgram == "NETWORK") {
		degreeProgram = NETWORK;
	}
	else {
		degreeProgram = SOFTWARE;
	}

	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
};

void Roster::add(string studentID, string firstName, string lastName, string emailAddress,
	int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {

	int daysInCourses[] = {daysInCourse1, daysInCourse2, daysInCourse3};

	classRosterArray[nextIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourses, degreeProgram);
	
	nextIndex++;

};


void Roster::printAll() {

	cout << "Displaying all students: \n";

	for (int i = 0; i < this->classSize; ++i) {
		classRosterArray[i]->Print();
	}

	cout << "\n";

};

string Roster::rosterGetStudentID(int index) const {
	return classRosterArray[index]->GetStudentID();
};


void Roster::printAverageDaysInCourse(string studentID) {
	

	for (int i = 0; i < classSize; ++i) {
		
		if (classRosterArray[i]->GetStudentID() == studentID) {
			int* days = classRosterArray[i]->GetDaysInCourses();
			int averageDaysInCourse = (days[0] + days[1] + days[2]) / 3;
			cout << "Student ID: " << studentID << ", average days in course is: " << averageDaysInCourse << "\n";
			return;
		}
	}	

};


//valid email should include an at sign('@') and period('.') and should not include a space(' ')
void Roster::printInvalidEmails() {
	
	cout << "Displaying invalid emails: \n\n";

	for (int i = 0; i < classSize; ++i) {
		
		string email = classRosterArray[i]->GetEmailAddress();
		
		size_t emailAt = email.find('@');
		size_t emailPeriod = email.find('.');
		size_t emailSpace = email.find(' ');

		if (emailAt == -1 || emailPeriod == -1 || emailSpace != -1) {
			cout << email << " - is invalid.\n";
		}

	}

	cout << "\n\n";

};




void Roster::remove(string studentID) {
	
	for (int i = 0; i < classSize; ++i) {
		if (classRosterArray[i]->GetStudentID() == studentID) {

			for (int j = i; j < classSize - 1; ++j)
			{
				classRosterArray[j] = classRosterArray[j + 1];
			}
			classRosterArray[classSize - 1] = nullptr;
			classSize--;

			return;
		}
	}

	cout << "The student with the ID: " << studentID << " was not found.\n\n";

	return;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	
	cout << "\n\nShowing students in degree program: ";

	if (degreeProgram == SECURITY) {
		cout << "SECURITY\n\n";
	}
	else if (degreeProgram == NETWORK) {
		cout << "NETWORK\n\n";
	}
	else {
		cout << "SOFTWARE\n\n";
	}

	for (int i = 0; i < classSize; ++i) {

		if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
			classRosterArray[i]->Print();
		}
	}
};

Roster::~Roster() {
	
	for (int i = 0; i < classSize; ++i) {
		delete classRosterArray[i];
	}
	
};