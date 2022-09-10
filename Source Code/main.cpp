// C867 Scripting and Programming Performance Assessment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include "degree.h"
#include "student.h"
#include "roster.h"
using namespace std;

int main()
{
    cout << "C867 - Scripting & Programming - Applications\n";
    cout << "Language: C++\n";
    cout << "Student ID: 010102640\n";
    cout << "Name: Luke Penner\n\n";
     
    const string studentData[] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Luke,Penner,lpenne4000@wgu.edu,35,20,30,40,SOFTWARE"
    };

    Roster classRoster;

    //parse student data and add each student to classRoster
    for (int i = 0; i < 5; ++i) {
        classRoster.parse(studentData[i]);
    }
        
    classRoster.printAll();

    classRoster.printInvalidEmails();

    for (int i = 0; i < 5; ++i) {
        classRoster.printAverageDaysInCourse(classRoster.rosterGetStudentID(i));
    }
    
    classRoster.printByDegreeProgram(SOFTWARE);

    cout << "\nRemoving A3\n\n";
    classRoster.remove("A3");

    classRoster.printAll();

    cout << "Removing A3 again\n\n";
    classRoster.remove("A3");

    //call destructor to release memory
    classRoster.~Roster();

    cout << "DONE\n";

}

