#include <iostream>

using namespace std;

#include "student.h"

//default constructor
Student::Student() {
	studentID = "TBD";
	firstName = "TBD";
	lastName = "TBD";
	emailAddress = "TBD";
	age = 0;
	for (int i = 0; i < 3; i++) daysInCourses[i] = 0;
	degreeProgram = SOFTWARE;
}

//constructor with data
Student::Student(string initStudentID, string initFirstName, string initLastName,
	string initEmailAddress, int initAge, int initDaysInCourses[], DegreeProgram initDegreeProgram) {

	studentID = initStudentID;
	firstName = initFirstName;
	lastName = initLastName;
	emailAddress = initEmailAddress;
	age = initAge;
	
	daysInCourses = new int[3];
	for (int i = 0; i < 3; ++i) {
		daysInCourses[i] = initDaysInCourses[i];
	}
	
	degreeProgram = initDegreeProgram;
}

//mutator functions
void Student::SetStudentID(string assignedStudentID) {
	studentID = assignedStudentID;
};

void Student::SetFirstName(string studentFirstName) {
	firstName = studentFirstName;
};

void Student::SetLastName(string studentLastName) {
	lastName = studentLastName;
};

void Student::SetEmailAddress(string studentEmailAddress) {
	emailAddress = studentEmailAddress;
};

void Student::SetAge(int studentAge) {
	age = studentAge;
};


void Student::SetDaysInCourses(int studentDaysInCourses[]) {
	daysInCourses = new int[3];
	for (int i = 0; i < 3; i++) daysInCourses[i] = studentDaysInCourses[i];
};



void Student::SetDegreeProgram(DegreeProgram studentDegreeProgram) {
	degreeProgram = studentDegreeProgram;
};


//accessor functions
string Student::GetStudentID() const {
	return studentID;
};

string Student::GetFirstName() const {
	return firstName;
};

string Student::GetLastName() const {
	return lastName;
};

string Student::GetEmailAddress() const {
	return emailAddress;
};

int Student::GetAge() const {
	return age;
};

int* Student::GetDaysInCourses() const {
	return daysInCourses;
};


DegreeProgram Student::GetDegreeProgram() const {
	return degreeProgram;
};

//print function
void Student::Print() const {
	cout << studentID << "\t" << firstName << "\t" << lastName << "\t" << emailAddress
		<< "\t" << age << "\t" << daysInCourses[0] << daysInCourses[1] << daysInCourses[2] << "\t";
	
	if (degreeProgram == SECURITY) {
		cout << "SECURITY\n";
	}
	else if (degreeProgram == NETWORK) {
		cout << "NETWORK\n";
	}
	else {
		cout << "SOFTWARE\n";
	}
		
};
