#ifndef STUDENT_H
#define STUDENT_H

#include<string>
#include "degree.h"
using namespace std;

class Student {
public:
	//constructors
	Student();
	Student(string initStudentID, string initFirstName, string initLastName,
		string initEmailAddress, int initAge, int initDaysInCourses[], DegreeProgram initDegreeProgram);

	//mutator functions
	void SetStudentID(string assignedStudentID);
	void SetFirstName(string studentFirstName);
	void SetLastName(string studentLastName);
	void SetEmailAddress(string studentEmailAddress);
	void SetAge(int studentAge);
	void SetDaysInCourses(int studentDaysInCourses[]);
	void SetDegreeProgram(DegreeProgram studentDegreeProgram);

	//accessor functions
	string GetStudentID() const;
	string GetFirstName() const;
	string GetLastName() const;
	string GetEmailAddress() const;
	int GetAge() const;
	int* GetDaysInCourses() const;
	DegreeProgram GetDegreeProgram() const;

	//print function
	void Print() const;

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int* daysInCourses;
	DegreeProgram degreeProgram;
};

#endif // !STUDENT_H
